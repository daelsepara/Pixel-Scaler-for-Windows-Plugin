# Pixel-Scaler-for-Windows-Plugin
How to create a plugin DLL for Pixel Scaler

## Image format

The filter's input and output format is raw 8-bit RGB without an alpha channel. This is essentially an __unsigned char__  array in C/C++ terms. The size of the array is __Width * Height * 3__, i.e. *1 byte* for each color channel. In the future this might change.

## Required Exports

Although there is strictly no pre-defined way to code a filter plugin that will work with PixelScaler, the following functions are expected by the program

__void Release()__

This is where you perform clean-up procedures such as freeing resources, especially the filter's scaled output. This is called before the DLL is unloaded by PixelScaler.

__void Apply(int argc, void** argv)__

Actual application of the filter occurs here. Two arguments are passed in this function, the number of arguments __*argc*__, and an array of pointers __*argv*__ to the actual parameters. PixelScaler assumes that the first 3 arguments are:

* pointer to the input image (in 8-bit RGB format as described above), i.e. __unsigned char* Input__
* pointer to an integer variable indicating the width of the input, i.e. __int* Width__
* pointer to an integer variable indicating the height of the input, i.e. __int* Width__

Beyond the first three parameters, you have absolute freedom on how to process it. In the sample code provided here, the parameter values are read in the following manner:

```c
      auto Input = ((unsigned char*)(argv[0]));
			auto srcx = *((int*)(argv[1]));
			auto srcy = *((int*)(argv[2]));
```
Code to process other parameters (__argv[3]__ and beyond) can easily adapted from the above example

__void Threshold(bool threshold)__

Passing a __true__ value to this function indicates that the color comparison in *FilterCommon.h* should use *Luminance*, *Chromaticity U*, and *V* thresholds when comparing pixel colors. The default setting for the internal variable is __false__. 

__int ID()__

This  returns a numeric (*integer*) ID for your filter plugin. This may or may not be unique.

__int Scale()__

Indicates scaling factor of the filter's output. For *2 X* magnification, this should return __2__

__int Parameters()__

This just returns the number of special parameters that your plugin can handle. PixelScaler does not *actively* use this yet, but this is for future expansions. For now, it returns __0__

__const char* Name()__

The name of the plugin

__const char* Description()__

Brief description of the plugin

__unsigned char* Image()__

Returns a pointer to the raw 8-bit RGB __unsigned char__ buffer containing the most recent output (if any) of the filter, otherwise, it is __null__.
