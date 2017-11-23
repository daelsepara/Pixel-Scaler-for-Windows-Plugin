// clone.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "FilterCommon.h"

extern "C"
{
	static unsigned char* ScaledImage = NULL;

	const int FilterID = 0x0000;
	const int FilterScale = 1;
	const char* FilterName = "Clone";
	const char* FilterDescription = "Clone Bitmap without Magnification.";
	bool ComparisonThreshold = false;

	unsigned char* Buffer(int Length, unsigned char c)
	{
		auto Channels = 3;

		auto buffer = (unsigned char*)malloc(Length * Channels);

		for (auto i = 0; i < Length; i++)
		{
			auto index = i * Channels;

			buffer[index] = c;
			buffer[index + 1] = c;
			buffer[index + 2] = c;
		}

		return buffer;
	}

	unsigned char* New(int x, int y)
	{
		return Buffer(x * y, (unsigned char)0);
	}

	void Init(int srcx, int srcy)
	{
		_Scale = FilterScale;
		_Threshold = ComparisonThreshold;

		free(ScaledImage);

		ScaledImage = New(srcx * FilterScale, srcy * FilterScale);
	}

	DECLDIR int ID()
	{
		return FilterID;
	}

	DECLDIR int Parameters()
	{
		// No Special Parameters
		return 0;
	}

	DECLDIR int Scale()
	{
		return FilterScale;
	}

	DECLDIR const char* Name()
	{
		return FilterName;
	}

	DECLDIR const char* Description()
	{
		return FilterDescription;
	}

	DECLDIR unsigned char* Image()
	{
		return ScaledImage;
	}

	DECLDIR void Threshold(bool threshold)
	{
		ComparisonThreshold = threshold;
	}

	DECLDIR void Apply(int argc, void** argv)
	{
		if (argc >= 3)
		{
			auto Input = ((unsigned char*)(argv[0]));
			auto srcx = *((int*)(argv[1]));
			auto srcy = *((int*)(argv[2]));

			Init(srcx, srcy);

			for (auto y = 0; y < srcy; y++)
			{
				for (auto x = 0; x < srcx; x++)
				{
					WriteMagnify(Input, ScaledImage, srcx, srcy, x, y);
				}
			}
		}
	}

	DECLDIR void Release()
	{
		free(ScaledImage);

		ScaledImage = NULL;
	}
}


