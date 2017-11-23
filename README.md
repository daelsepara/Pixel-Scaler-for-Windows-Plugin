# Pixel-Scaler-for-Windows-Plugin
How to create a plugin DLL for Pixel Scaler

## Output format

The filter's output fornow is raw 8-bit RGB, without an alpha channel. This is essentially an __unsigned char__  array in C/C++ terms. The size of the array is __Width * Height * 3__, i.e. *1 byte* for each color channel. 

## Required Exports

Although there is strictly no pre-defined way to code a filter plugin that will work with PixelScaler, the following functions are expected by the program:

__void Release()__

This is where you perform clean-up procedures such as freeing resources, especially the filter's scaled output

__void Apply(int argc, void** argv)__

__void Threshold(bool threshold)__

__int ID()__

__int Scale()__

__int Parameters()__

__const char* Name()__

__const char* Description()__

__unsigned char* Image()__

