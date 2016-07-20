
// Author: Christian Vallentin <mail@vallentinsource.com>
// Website: http://vallentinsource.com
// Repository: https://github.com/MrVallentin/GameMath
//
// Date Created: September 24, 2012
// Last Modified: July 20, 2016

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

#ifndef GM_MATH_HPP
#define GM_MATH_HPP


#include <math.h>


#define GM_PI 3.1415926535897932

#define GM_TWO_PI (GM_PI * 2.0)

#define GM_PI_SQUARED (GM_PI * GM_PI)

#define GM_HALF_PI (GM_PI / 2.0)
#define GM_THIRD_PI (GM_PI / 3.0)
#define GM_QUARTER_PI (GM_PI / 4.0)

#define GM_TAU (GM_PI * 2.0)

#define GM_DEG2RAD (GM_PI / 180.0)
#define GM_RAD2DEG (180.0 / GM_PI)

#define GM_EPSILON 1E-6

#define GM_E 2.7182818284590452


#ifndef GM_NO_NAMESPACE
namespace gm {
#endif


template<typename T> T rad(const T &degrees);
template<typename T> T radians(const T &degrees);

template<typename T> T deg(const T &radians);
template<typename T> T degrees(const T &radians);


template<typename T> T abs(const T &x);


template<typename T> T ceil(const T &x);
template<typename T> T floor(const T &x);
template<typename T> T round(const T &x);


// Rounds n to the nearest multiple of x. You can force the direction
// of the rounding by using either nearestCeil() or nearestFloor().
template<typename T> T nearest(const T &n, const T &x);
template<typename T> T nearestCeil(const T &n, const T &x);
template<typename T> T nearestFloor(const T &n, const T &x);


// Returns the fractional part of x.
template<typename T> T fract(const T &x);


// Returns the maximum/minimum value. If a and b
// equal then a is returned.
template<typename T> T max(const T &a, const T &b);
template<typename T> T min(const T &a, const T &b);

template<typename T, typename... Args> T max(const T &a, const T &b, const Args &...args);
template<typename T, typename... Args> T min(const T &a, const T &b, const Args &...args);


template<typename T> T clamp(const T &x, const T &min, const T &max);


template<typename T> bool even(const T &x);
template<typename T> bool odd(const T &x);

template<typename T> bool isEven(const T &x);
template<typename T> bool isOdd(const T &x);


template<typename T> T sign(const T &x);


template<typename T> T lerp(const T &from, const T &to, const T &t);

template<typename T> T map(const T &value, const T &min1, const T &max1, const T &min2, const T &max2);

// Normalize a value between a range.
template<typename T> T normalize(const T &from, const T &to, const T &value);

// edge0 - Specifies the value of the lower edge of the Hermite function.
// edge1 - Specifies the value of the upper edge of the Hermite function.
// x     - Specifies the source value for interpolation.
// 
// Reference: https://www.opengl.org/sdk/docs/man/html/smoothstep.xhtml
template<typename T> T smoothstep(const T &edge0, const T &edge1, const T &x);

template<typename T> T bilerp(const T &p00, const T &p10, const T &p01, const T &p11, const T &u, const T &v);


// Critically Damped Spring
template<typename T> T smoothDamp(const T &current, const T &target, T &velocity, const T &timeStep, const T &springiness = T(5));


// All angles are in radins.
// - rho = distance from origin O to point P (i.e. the length of OP)
// - phi = angle between OP and the XZ plane
// - theta = angle between X-axis and OP projected onto XZ plane
template<typename T> void cartesianToSpherical(const T &x, const T &y, const T &z, T &rho, T &phi, T &theta);

// All angles are in radians.
// - rho = distance from origin O to point P (i.e. the length of OP)
// - phi = angle between OP and the XZ plane
// - theta = angle between X-axis and OP projected onto XZ plane
template<typename T> void sphericalToCartesian(const T &rho, const T &phi, const T &theta, T &x, T &y, T &z);


// Determines whether the two values (a and b) are
// close enough together that they can be considered equal.
template<typename T> bool closeEnough(const T &a, const T &b);

template<typename T> bool inBounds(const T &a, const T &b, const T &bounds);

template<typename T> bool isPowerOfTwo(const unsigned int &x);


template<typename T> bool isInteger(const T &value);
template<typename T> bool hasDecimals(const T &value);


// Example:
//   sqrt(x) == root(x, 2)
//   cbrt(x) == root(x, 3)
//
// Always use the built-in sqrt and cbrt functions instead.
template<typename T> T root(const T &x, const T &n);


// After this point everything you'll see is all
// the definitions to the prior declarations.


template<> inline double rad(const double &degrees)
{
	return (degrees * 3.1415926535897932 / 180.0);
}

template<> inline float rad(const float &degrees)
{
	return (degrees * 3.1415926535897932f / 180.0f);
}

template<typename T> inline T rad(const T &degrees)
{
	return static_cast<T>(rad(static_cast<double>(degrees)));
}


template<> inline double radians(const double &degrees)
{
	return (degrees * 3.1415926535897932 / 180.0);
}

template<> inline float radians(const float &degrees)
{
	return (degrees * 3.1415926535897932f / 180.0f);
}

template<typename T> inline T radians(const T &degrees)
{
	return static_cast<T>(radians(static_cast<double>(degrees)));
}


template<> inline double deg(const double &radians)
{
	return (radians * 180.0 / 3.1415926535897932);
}

template<> inline float deg(const float &radians)
{
	return (radians * 180.0f / 3.1415926535897932f);
}

template<typename T> inline T deg(const T &radians)
{
	return static_cast<T>(deg(static_cast<double>(radians)));
}


template<> inline double degrees(const double &radians)
{
	return (radians * 180.0 / 3.1415926535897932);
}

template<> inline float degrees(const float &radians)
{
	return (radians * 180.0f / 3.1415926535897932f);
}

template<typename T> inline T degrees(const T &radians)
{
	return static_cast<T>(radians(static_cast<double>(radians)));
}


template<typename T> inline T abs(const T &x)
{
	return ((x > T(0)) ? x : -x);
}


template<typename T> inline T ceil(const T &x)
{
	return (((x >= T(0)) && (x != static_cast<int>(x))) ? (static_cast<int>(x) + 1) : static_cast<int>(x));
}

template<typename T> inline T floor(const T &x)
{
	return (((x < T(0)) && (x != static_cast<int>(x))) ? (static_cast<int>(x) - 1) : static_cast<int>(x));
}

template<typename T> inline T round(const T &x)
{
	return (((x - static_cast<int>(x)) >= T(0.5)) ? ceil<T>(x) : floor<T>(x));
}


template<typename T> inline T nearest(const T &n, const T &x)
{
	return (round<T>(n / x) * x);
}

template<typename T> inline T nearestCeil(const T &n, const T &x)
{
	return (ceil<T>(n / x) * x);
}

template<typename T> inline T nearestFloor(const T &n, const T &x)
{
	return (floor<T>(n / x) * x);
}


template<typename T> inline T fract(const T &x)
{
	return (x - floor<T>(x));
}


template<typename T> inline T max(const T &a, const T &b)
{
	return (a < b) ? b : a;
}

template<typename T, typename... Args> T max(const T &a, const T &b, const Args &...args)
{
	return max(max(a, b), args...);
}


template<typename T> inline T min(const T &a, const T &b)
{
	return (a > b) ? b : a;
}

template<typename T, typename... Args> T min(const T &a, const T &b, const Args &...args)
{
	return min(min(a, b), args...);
}


template<typename T> inline T clamp(const T &x, const T &min, const T &max)
{
	return ((x > max) ? max : ((min > x) ? min : x));
}


template<typename T> inline bool even(const T &x)
{
	return ((x % 2) == 0);
}

template<typename T> inline bool odd(const T &x)
{
	return !even(x);
}


template<typename T> inline bool isEven(const T &x)
{
	return ((x % 2) == 0);
}

template<typename T> inline bool isOdd(const T &x)
{
	return !isEven(x);
}


template<typename T> T sign(const T &x)
{
	if (x > T(0)) return T(1);
	if (x < T(0)) return T(-1);

	return T(0);
}


template<typename T> inline T lerp(const T &from, const T &to, const T &t)
{
	// return (from + t * (to - from)); // Imprecise
	return ((T(1) - t) * from + t * to); // Precise
}

template<typename T> inline T map(const T &value, const T &min1, const T &max1, const T &min2, const T &max2)
{
	return (min2 + (max2 - min2) * ((value - min1) / (max1 - min1)));
}


template<typename T> inline T normalize(const T &from, const T &to, const T &value)
{
	return ((value - from) / (to - from));
}


template<typename T> T smoothstep(const T &edge0, const T &edge1, const T &x)
{
	const T t = clamp<T>((x - edge0) / (edge1 - edge0), T(0), T(1));
	return t * t * (T(3) - T(2) * t);
}


template<typename T> inline T bilerp(const T &p00, const T &p10, const T &p01, const T &p11, const T &u, const T &v)
{
	return
		p00 * ((T(1) - u) * (T(1) - v)) +
		p10 * (u * (T(1) - v)) +
		p01 * (v * (T(1) - u)) +
		p11 * (u * v);
}


template<typename T> T smoothDamp(const T &current, const T &target, T &velocity, const T &timeStep, const T &springiness)
{
	const T delta = target - current;
	const T springForce = delta * springiness;
	const T dampingForce = -velocity * T(2) * sqrt(springiness);
	const T force = springForce + dampingForce;

	velocity += force * timeStep;

	const T displacement = velocity * timeStep;

	return current + displacement;
}


template<typename T> void cartesianToSpherical(const T &x, const T &y, const T &z, T &rho, T &phi, T &theta)
{
	rho = sqrt((x * x) + (y * y) + (z * z));
	phi = asin(y / rho);
	theta = atan2(z, x);
}

template<typename T> void sphericalToCartesian(const T &rho, const T &phi, const T &theta, T &x, T &y, T &z)
{
	x = rho * cos(phi) * cos(theta);
	y = rho * sin(phi);
	z = rho * cos(phi) * sin(theta);
}


template<typename T> inline bool closeEnough(const T &a, const T &b)
{
	return (abs<T>(a - b) <= T(GM_EPSILON));
}

template<typename T> inline bool inBounds(const T &a, const T &b, const T &bounds)
{
	return (abs<T>(a - b) < bounds);
}

template<typename T> inline bool isPowerOfTwo(const unsigned int &x)
{
	return ((x > 0) && ((x & (x - 1)) == 0));
}


template<typename T> inline bool isInteger(const T &value)
{
	return (closeEnough<T>(static_cast<T>(static_cast<int>(value)), value));
}

template<typename T> inline bool hasDecimals(const T &value)
{
	return !isInteger(value);
}


template<typename T> inline T root(const T &x, const T &n)
{
	return static_cast<T>(pow(static_cast<double>(x), 1.0 / static_cast<double>(n)));
}


#ifndef GM_NO_NAMESPACE
}
#endif


#endif