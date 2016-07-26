
# GameMath ![Release][GameMathVersionBadge] ![License][GameMathLicenseBadge]

[GameMath][GameMath] is a collection of single-header libraries for various
game and graphics related mathematics.


Library | Latest Version | Description
--------|----------------|------------
gm_math.hpp | 1.0.0 | Like `math.h` but for gamedev specific functions
gm_color.hpp | 1.1.0 | Contains functionality for converting between color models and changing colorfulness
gm_easing.hpp | 1.0.0 | Contains simple easing functions


[GameMath][GameMath] is compatible with both C and C++. Files denoted with `.h`
is compatible with both C and C++, whereas files denoted with `.hpp` is only
compatible with C++.


## Libraries


### Math (`gm_math.hpp`)

If you're developing on Windows and have any Windows headers
included. Then macros `min` and `max` might have been defined.
This will (at least) break `gm_math.hpp` (as well as `gm_linear.hpp`).

To counteract this either `#undef` `min` and `max` or `#define` `NOMINMAX`
before including any Windows headers.


### Color (`gm_color.hpp`)

#### HSL & RGB Conversion

Depending on the software HSL is represented in different
ranges. **H**ue, **S**aturation and **L**ightness (or brightness)
is usually represented as a range between [0;240]. As HSL is
also visually represented as a cylinder, H, S, L is thereby usually
represented as Hue being an angle from [0;360] and Saturation and
Lightness being a percentage [0;100%].

For ease of use the library's HSL and RGB converter takes and
outputs in the range of [0;1].


## Reporting Bugs & Requests

Feel free to use the [issue tracker][GameMathIssues],
for reporting bugs, submitting patches or requesting features.

Before submitting bugs, make sure that you're using the latest version of [GameMath][GameMath].


## License

```
GameMath <https://github.com/MrVallentin/GameMath>

Copyright (c) 2012-2016 Christian Vallentin <mail@vallentinsource.com>

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not
   be misrepresented as being the original software.

3. This notice may not be removed or altered from any source
   distribution.
```


[GameMath]: https://github.com/MrVallentin/GameMath
[GameMathLicense]: https://github.com/MrVallentin/GameMath/blob/master/LICENSE

[GameMathVersionBadge]: https://img.shields.io/badge/release-v1.0.0-blue.svg
[GameMathLicenseBadge]: https://img.shields.io/badge/license-%20free%20to%20use%2C%20share%2C%20modify%20and%20redistribute-blue.svg

[GameMathIssues]: https://github.com/MrVallentin/GameMath/issues
