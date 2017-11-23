# Pixel-Scaler-for-Windows-Plugin
How to create a plugin DLL for Pixel Scaler
 
## Required Exports

Although there is strictly no pre-defined way to code a filter plugin that will work with PixelScaler, the following functions are expected by the program:

* void Release()
* void Apply(int argc, void** argv)
* void Threshold(bool threshold)
* int ID()
* int Scale()
* int Parameters()
* const char* Name()
* const char* Description()
* unsigned char* Image()

