// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

#define DECLDIR __declspec(dllexport)

extern "C"
{
	DECLDIR void Release();
	DECLDIR void Apply(int argc, void** argv);
	DECLDIR void Threshold(bool threshold);
	DECLDIR int ID();
	DECLDIR int Scale();
	DECLDIR int Parameters();
	DECLDIR const char* Name();
	DECLDIR const char* Description();
	DECLDIR unsigned char* Image();
}
