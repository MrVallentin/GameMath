
// Author: Christian Vallentin <mail@vallentinsource.com>
// Website: http://vallentinsource.com
// Repository: https://github.com/MrVallentin/GameMath
//
// Date Created: November 12, 2012
// Last Modified: July 24, 2016

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

#ifndef GM_EASING_HPP
#define GM_EASING_HPP


#ifndef GM_STRINGIFY_VERSION
#	define _GM_STRINGIFY(str) #str
#	define _GM_STRINGIFY_TOKEN(str) _GM_STRINGIFY(str)
#	define GM_STRINGIFY_VERSION(major, minor, patch) _GM_STRINGIFY(major) "." _GM_STRINGIFY(minor) "." _GM_STRINGIFY(patch)
#endif


#define GM_EASING_NAME "GameMath Easing"

#define GM_EASING_VERSION_MAJOR 1
#define GM_EASING_VERSION_MINOR 0
#define GM_EASING_VERSION_PATCH 0

#define GM_EASING_VERSION GM_STRINGIFY_VERSION(GM_EASING_VERSION_MAJOR, GM_EASING_VERSION_MINOR, GM_EASING_VERSION_PATCH)

#define GM_EASING_NAME_VERSION GM_EASING_NAME " " GM_EASING_VERSION


#define _GM_EASING_FEPSILON 1E-4
#define _GM_EASING_DEPSILON 1E-4f

#define _GM_EASING_FEQUAL(x, y) ((((y) - _GM_EASING_FEPSILON) < (x)) && ((x) < ((y) + _GM_EASING_FEPSILON)))
#define _GM_EASING_DEQUAL(x, y) ((((y) - _GM_EASING_DEPSILON) < (x)) && ((x) < ((y) + _GM_EASING_DEPSILON)))


#define GM_EASING_API static


#ifndef GM_NO_NAMESPACE
namespace gm {
#endif

namespace easing {


template<typename T> GM_EASING_API T easeLinear(const T time);

template<typename T> GM_EASING_API T easeInQuad(const T time);
template<typename T> GM_EASING_API T easeOutQuad(const T time);
template<typename T> GM_EASING_API T easeInOutQuad(T time);

template<typename T> GM_EASING_API T easeInCubic(const T time);
template<typename T> GM_EASING_API T easeOutCubic(const T time);
template<typename T> GM_EASING_API T easeInOutCubic(T time);

template<typename T> GM_EASING_API T easeInQuart(const T time);
template<typename T> GM_EASING_API T easeOutQuart(const T time);
template<typename T> GM_EASING_API T easeInOutQuart(T time);

template<typename T> GM_EASING_API T easeInQuint(const T time);
template<typename T> GM_EASING_API T easeOutQuint(const T time);
template<typename T> GM_EASING_API T easeInOutQuint(T time);

template<typename T> GM_EASING_API T easeInSine(const T time);
template<typename T> GM_EASING_API T easeOutSine(const T time);
template<typename T> GM_EASING_API T easeInOutSine(const T time);

template<typename T> GM_EASING_API T easeInExpo(const T time);
template<typename T> GM_EASING_API T easeOutExpo(const T time);
template<typename T> GM_EASING_API T easeInOutExpo(T time);

template<typename T> GM_EASING_API T easeInCirc(const T time);
template<typename T> GM_EASING_API T easeOutCirc(const T time);
template<typename T> GM_EASING_API T easeInOutCirc(T time);

template<typename T> GM_EASING_API T easeInBack(const T time);
template<typename T> GM_EASING_API T easeOutBack(T time);
template<typename T> GM_EASING_API T easeInOutBack(T time);

template<typename T> GM_EASING_API T easeInElastic(const T time);
template<typename T> GM_EASING_API T easeOutElastic(const T time);
template<typename T> GM_EASING_API T easeInOutElastic(const T time);

template<typename T> GM_EASING_API T easeInBounce(const T time);
template<typename T> GM_EASING_API T easeOutBounce(const T time);
template<typename T> GM_EASING_API T easeInOutBounce(const T time);


// After this point everything you'll see is all
// the definitions to the prior declarations.


template<typename T> GM_EASING_API inline T easeLinear(const T time)
{
	return time;
}


template<typename T> GM_EASING_API inline T easeInQuad(const T time)
{
	return (time * time);
}

template<typename T> GM_EASING_API inline T easeOutQuad(const T time)
{
	return -(((time - T(1)) * (time - T(1))) - T(1));
}

template<typename T> GM_EASING_API inline T easeInOutQuad(T time)
{
	return (((time *= T(2)) < T(1)) ? (T(0.5) * time * time) : (T(-0.5) * ((time -= T(2)) * time - T(2))));
}


template<typename T> GM_EASING_API inline T easeInCubic(const T time)
{
	return (time * time * time);
}

template<typename T> GM_EASING_API inline T easeOutCubic(const T time)
{
	return ((time - T(1)) * (time - T(1)) * (time - T(1)) + T(1));
}

template<typename T> GM_EASING_API inline T easeInOutCubic(T time)
{
	return (((time /= T(0.5)) < T(1)) ? (T(0.5) * time * time * time) : (T(0.5) * ((time - T(2)) * (time - T(2)) * (time - T(2)) + T(2))));
}


template<typename T> GM_EASING_API inline T easeInQuart(const T time)
{
	return (time * time * time * time);
}

template<typename T> GM_EASING_API inline T easeOutQuart(const T time)
{
	return -((time - T(1)) * (time - T(1)) * (time - T(1)) * (time - T(1)) - T(1));
}

template<typename T> GM_EASING_API inline T easeInOutQuart(T time)
{
	return (((time *= T(2)) < T(1)) ? (T(0.5) * time * time * time * time) : (-T(0.5) * ((time -= T(2)) * time * time * time - T(2))));
}


template<typename T> GM_EASING_API inline T easeInQuint(const T time)
{
	return (time * time * time * time * time);
}

template<typename T> GM_EASING_API inline T easeOutQuint(const T time)
{
	return ((time - T(1)) * (time - T(1)) * (time - T(1)) * (time - T(1)) * (time - T(1)) + T(1));
}

template<typename T> GM_EASING_API inline T easeInOutQuint(T time)
{
	return (((time *= T(2)) < T(1)) ? (T(0.5) * time * time * time * time * time) : (T(0.5) * ((time - T(2)) * (time - T(2)) * (time - T(2)) * (time - T(2)) * (time - T(2)) + T(2))));
}


template<typename T> GM_EASING_API inline T easeInSine(const T time)
{
	return -cos(time * (T(3.1415926535897932) / T(2))) + T(1);
}

template<> GM_EASING_API inline float easeInSine(const float time)
{
	return -cosf(time * (3.1415926535897932f / 2.0f)) + 1.0f;
}

template<typename T> GM_EASING_API inline T easeOutSine(const T time)
{
	return sin(time * (T(3.1415926535897932) / T(2)));
}

template<> GM_EASING_API inline float easeOutSine(const float time)
{
	return sinf(time * (3.1415926535897932f / 2.0f));
}

template<typename T> GM_EASING_API inline T easeInOutSine(const T time)
{
	return (T(-0.5) * (cos(T(3.1415926535897932) * time) - T(1)));
}

template<> GM_EASING_API inline float easeInOutSine(const float time)
{
	return (-0.5f * (cosf(3.1415926535897932f * time) - 1.0f));
}


template<typename T> GM_EASING_API inline T easeInExpo(const T time)
{
	return (_GM_EASING_DEQUAL(time, T(0)) ? T(0) : pow(T(2), T(10) * (time - T(1))));
}

template<> GM_EASING_API inline float easeInExpo(const float time)
{
	return (_GM_EASING_FEQUAL(time, 0.0f) ? 0.0f : powf(2.0f, 10.0f * (time - 1.0f)));
}

template<typename T> GM_EASING_API inline T easeOutExpo(const T time)
{
	return (_GM_EASING_DEQUAL(time, T(1)) ? T(1) : -pow(T(2), T(-10) * time) + T(1));
}

template<> GM_EASING_API inline float easeOutExpo(const float time)
{
	return (_GM_EASING_FEQUAL(time, 1.0f) ? 1.0f : -powf(2.0f, -10.0f * time) + 1.0f);
}

template<typename T> GM_EASING_API inline T easeInOutExpo(T time)
{
	return (_GM_EASING_DEQUAL(time, T(0)) ? T(0) : (_GM_EASING_DEQUAL(time, T(1)) ? T(1) : (((time *= T(2)) < T(1)) ? (T(0.5) * pow(T(2), T(10) * (time - T(1)))) : (T(0.5) * (-pow(T(2), T(-10) * --time) + T(2))))));
}

template<> GM_EASING_API inline float easeInOutExpo(float time)
{
	return (_GM_EASING_FEQUAL(time, 0.0f) ? 0.0f : (_GM_EASING_FEQUAL(time, 1.0f) ? 1.0f : (((time *= 2.0f) < 1.0f) ? (0.5f * powf(2.0f, 10.0f * (time - 1.0f))) : (0.5f * (-powf(2.0f, -10.0f * --time) + 2.0f)))));
}


template<typename T> GM_EASING_API inline T easeInCirc(const T time)
{
	return -(sqrt(T(1) - time * time) - T(1));
}

template<> GM_EASING_API inline float easeInCirc(const float time)
{
	return -(sqrtf(1.0f - time * time) - 1.0f);
}

template<typename T> GM_EASING_API inline T easeOutCirc(const T time)
{
	return sqrt(T(1) - (time - T(1)) * (time - T(1)));
}

template<> GM_EASING_API inline float easeOutCirc(const float time)
{
	return sqrtf(1.0f - (time - 1.0f) * (time - 1.0f));
}

template<typename T> GM_EASING_API inline T easeInOutCirc(T time)
{
	return (((time *= T(2)) < T(1)) ? (T(-0.5) * (sqrt(T(1) - time * time) - T(1))) : (T(0.5) * (sqrt(T(1) - (time -= T(2)) * time) + T(1))));
}

template<> GM_EASING_API inline float easeInOutCirc(float time)
{
	return (((time *= 2.0f) < 1.0f) ? (-0.5f * (sqrtf(1.0f - time * time) - 1.0f)) : (0.5f * (sqrtf(1.0f - (time -= 2.0f) * time) + 1.0f)));
}


template<typename T> GM_EASING_API inline T easeInBack(const T time)
{
	return (time * time * (T(2.70158) * time - T(1.70158)));
}

template<typename T> GM_EASING_API inline T easeOutBack(T time)
{
	return ((time -= T(1)) * time * (T(2.70158) * time + T(1.70158)) + T(1));
}

template<typename T> GM_EASING_API inline T easeInOutBack(T time)
{
	T s = T(1.70158);
	return (((time *= T(2)) < T(1)) ? (T(0.5) * (time * time * (((s *= T(1.525)) + T(1)) * time - s))) : (T(0.5) * ((time -= T(2)) * time * (((s *= T(1.525)) + T(1)) * time + s) + T(2))));
}


template<typename T> GM_EASING_API T easeInElastic(const T time)
{
	return sin(T(13) * (T(3.1415926535897932) / T(2)) * time) * pow(T(2), T(10) * (time - T(1)));
}

template<> GM_EASING_API float easeInElastic(const float time)
{
	return sinf(13.0f * (3.1415926535897932f / 2.0f) * time) * powf(2.0f, 10.0f * (time - 1.0f));
}

template<typename T> GM_EASING_API T easeOutElastic(const T time)
{
	return sin(T(-13) * (T(3.1415926535897932) / T(2)) * (time + T(1))) * pow(T(2), T(-10) * time) + T(1);
}

template<> GM_EASING_API float easeOutElastic(const float time)
{
	return sinf(-13.0f * (3.1415926535897932f / 2.0f) * (time + 1.0f)) * powf(2.0f, -10.0f * time) + 1.0f;
}

template<typename T> GM_EASING_API T easeInOutElastic(const T time)
{
	if (time < T(0.5))
		return T(0.5) * sin(T(13) * (T(3.1415926535897932) / T(2)) * (T(2) * time)) * pow(T(2), T(10) * ((T(2) * time) - T(1)));
	else
		return T(0.5) * (sin(T(-13) * (T(3.1415926535897932) / T(2)) * ((T(2) * time - T(1)) + T(1))) * pow(T(2), T(-10) * (T(2) * time - T(1))) + T(2));
}

template<> GM_EASING_API float easeInOutElastic(const float time)
{
	if (time < 0.5f)
		return 0.5f * sinf(13.0f * (3.1415926535897932f / 2.0f) * (2.0f * time)) * powf(2.0f, 10.0f * ((2.0f * time) - 1.0f));
	else
		return 0.5f * (sinf(-13.0f * (3.1415926535897932f / 2.0f) * ((2.0f * time - 1.0f) + 1.0f)) * powf(2.0f, -10.0f * (2.0f * time - 1.0f)) + 2.0f);
}


template<typename T> GM_EASING_API T easeInBounce(T time)
{
	return ((time < (T(1) / T(2.75))) ? (T(7.5625) * time * time) : ((time < (T(2) / T(2.75))) ? (T(7.5625) * (time -= (T(1.5) / T(2.75))) * time + T(0.75)) : ((time < (T(2.5) / T(2.75))) ? (T(7.5625) * (time -= (T(2.25) / T(2.75))) * time + T(0.9375)) : (T(7.5625) * (time -= (T(2.625) / T(2.75))) * time + T(0.984375)))));
}

template<typename T> GM_EASING_API T easeOutBounce(const T time)
{
	return (T(1) - easeInBounce(T(1) - time));
}

template<typename T> GM_EASING_API T easeInOutBounce(const T time)
{
	return ((time < T(0.5)) ? (T(0.5) * easeOutBounce(time * T(2))) : (T(0.5) * easeInBounce(time * T(2) - T(1)) + T(0.5)));
}


}

#ifndef GM_NO_NAMESPACE
}
#endif


#endif