
// Author: Christian Vallentin <mail@vallentinsource.com>
// Website: http://vallentinsource.com
// Repository: https://github.com/MrVallentin/GameMath
//
// Date Created: September 24, 2012
// Last Modified: July 26, 2016

// Copyright (c) 2012-2016 Christian Vallentin <mail@vallentinsource.com>
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.

// Refrain from using any exposed macros, functions
// or structs prefixed with an underscore. As these
// are only intended for internal purposes. Which
// additionally means they can be removed, renamed
// or changed between minor updates without notice.

#ifndef GM_COLOR_HPP
#define GM_COLOR_HPP


#ifndef GM_STRINGIFY_VERSION
#	define _GM_STRINGIFY(str) #str
#	define _GM_STRINGIFY_TOKEN(str) _GM_STRINGIFY(str)
#	define GM_STRINGIFY_VERSION(major, minor, patch) _GM_STRINGIFY(major) "." _GM_STRINGIFY(minor) "." _GM_STRINGIFY(patch)
#endif


#define GM_COLOR_NAME "GameMath Color"

#define GM_COLOR_VERSION_MAJOR 1
#define GM_COLOR_VERSION_MINOR 1
#define GM_COLOR_VERSION_PATCH 0

#define GM_COLOR_VERSION GM_STRINGIFY_VERSION(GM_COLOR_VERSION_MAJOR, GM_COLOR_VERSION_MINOR, GM_COLOR_VERSION_PATCH)

#define GM_COLOR_NAME_VERSION GM_COLOR_NAME " " GM_COLOR_VERSION


#include <math.h>


#define GM_COLOR_API static


#ifndef GM_NO_NAMESPACE
namespace gm {
#endif


GM_COLOR_API void int2rgb(const int rgb, int *r, int *g, int *b, int *a = nullptr);
GM_COLOR_API int rgb2int(const int r, const int g, const int b, const int a = 255);


// Any color range can be used, whether that
// is [0;1], [0;255] or something else.
template<typename T> GM_COLOR_API T grayscale(T r, T g, T b);


template<typename T> GM_COLOR_API void hue2rgb(
	const T &hue,
	T *r, T* g, T* b);


template<typename T> GM_COLOR_API void hsl2rgb(
	const T &h, const T &s, const T &l,
	T *r, T *g, T *b);

template<typename T> GM_COLOR_API void rgb2hsl(
	const T &r, const T &g, const T &b,
	T *h, T *s, T *l);


template<typename T> GM_COLOR_API void rgb2hcv(
	const T &r, const T &g, const T &b,
	T *h, T *c, T *v);


// After this point everything you'll see is all
// the definitions to the prior declarations.


GM_COLOR_API void int2rgb(const int rgb, int *r, int *g, int *b, int *a)
{
	if (a) (*a) = (rgb >> 24) & 0xFF;
	if (r) (*r) = (rgb >> 16) & 0xFF;
	if (g) (*g) = (rgb >> 8) & 0xFF;
	if (b) (*b) = rgb & 0xFF;
}

GM_COLOR_API int rgb2int(const int r, const int g, const int b, const int a)
{
	return ((a & 0xFF) << 24) | ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
}


template<typename T> GM_COLOR_API T grayscale(T r, T g, T b)
{
	// The human eye is more sensitive to green colors and the least to blue.
	// So weighting the color channels gives a more physically accurate result.
	// Reference: https://en.wikipedia.org/wiki/Grayscale

	// return (r + g + b) / T(3); // Good
	return (r * T(0.2126) + g * T(0.7152) + b * T(0.0722)); // Better
}

template<> GM_COLOR_API int grayscale(int r, int g, int b)
{
	return static_cast<int>(grayscale<double>(static_cast<double>(r) / 255.0, static_cast<double>(g) / 255.0, static_cast<double>(b) / 255.0) * 255.0);
}


template<typename T> GM_COLOR_API void hue2rgb(
	const T &hue,
	T *r, T* g, T* b)
{
	if (r) (*r) = abs(hue * T(6) - T(3)) - T(1);
	if (g) (*g) = T(2) - abs(hue * T(6) - T(2));
	if (b) (*b) = T(2) - abs(hue * T(6) - T(4));

	if (r) (*r) = (((*r) > T(1)) ? T(1) : ((T(0) > (*r)) ? T(0) : (*r)));
	if (g) (*g) = (((*g) > T(1)) ? T(1) : ((T(0) > (*g)) ? T(0) : (*g)));
	if (b) (*b) = (((*b) > T(1)) ? T(1) : ((T(0) > (*b)) ? T(0) : (*b)));
}


template<typename T> GM_COLOR_API void hsl2rgb(
	const T &h, const T &s, const T &l,
	T *r, T *g, T *b)
{
	hue2rgb<T>(h, r, g, b);

	const T c = (T(1) - abs(T(2) * l - T(1))) * s;

	if (r) (*r) = ((*r) - T(0.5)) * c + l;
	if (g) (*g) = ((*g) - T(0.5)) * c + l;
	if (b) (*b) = ((*b) - T(0.5)) * c + l;
}

template<typename T> GM_COLOR_API void rgb2hsl(
	const T &r, const T &g, const T &b,
	T *h, T *s, T *l)
{
	T c, v;
	rgb2hcv<T>(r, g, b, h, &c, &v);

	const T L = v - c * T(0.5);

	if (s) (*s) = c / (T(1) - abs(L * T(2) - T(1)) + T(1E-10));
	if (l) (*l) = L;
}


template<typename T> GM_COLOR_API void rgb2hcv(
	const T &r, const T &g, const T &b,
	T *h, T *c, T *v)
{
	T x, y, z, w;
	T x2, y2, z2;

	if (g < b)
	{
		x = b;
		y = g;
		z = T(-1);
		w = T(2) / T(3);
	}
	else
	{
		x = g;
		y = b;
		z = T(0);
		w = T(-1) / T(3);
	}

	if (r < x)
	{
		x2 = x;
		y2 = r;
		z2 = w;
	}
	else
	{
		x2 = r;
		y2 = x;
		z2 = z;
	}

	const T C = x2 - ((y2 > y) ? y : y2);

	if (h) (*h) = abs((y2 - y) / (T(6) * C + T(1E-10)) + z2);
	if (c) (*c) = C;
	if (v) (*v) = x2;
}


#ifndef GM_NO_NAMESPACE
}
#endif


#endif