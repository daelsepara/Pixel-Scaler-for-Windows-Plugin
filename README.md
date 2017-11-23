# Pixel-Scaler-for-Windows-Plugin
How to create a plugin DLL for Pixel Scaler

## Image format

The filter's input and output format is raw 8-bit RGB without an alpha channel. This is essentially an __unsigned char__  array in C/C++ terms. The size of the array is __Width * Height * 3__, i.e. *1 byte* for each color channel. In the future this might change.

## Required Exports

Although there is strictly no pre-defined way to code a filter plugin that will work with PixelScaler, the following functions are expected by the program

__void Release()__

This is where you perform clean-up procedures such as freeing resources, especially the filter's scaled output

__void Apply(int argc, void** argv)__

Actual application of the filter occurs here. Two arguments are passed in this function, the number of arguments __*argc*__, and an array of pointers __*argv*__ to the actual parameters. PixelScaler assumes that the first 3 arguments are:

* pointer to the input image (in 8-bit RGB format as described above), i.e. __unsigned char* Input__
* pointer to an integer variable indicating the width of the input, i.e. __int* Width__
* pointer to an integer variable indicating the height of the input, i.e. __int* Width__

Beyond the first three parameters, you have absolute freedom on how to process it. In the sample provided ...

__void Threshold(bool threshold)__

__int ID()__

__int Scale()__

__int Parameters()__

__const char* Name()__

__const char* Description()__

__unsigned char* Image()__

