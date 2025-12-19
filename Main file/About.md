# About

onyx.h is a custom library designed specifically for audio related projects. Its primary purpose is to move logic errors from runtime.

<h3>In brief</h3>

- It Creates "Smart" Numbers
    In C++, a double is just a raw number. In your library, a Quantity is a number that "knows" what it represents.
    It attaches unit Tag so the compiler knows if the number represents Hertz, Decibels, or Milliseconds.

- The library prevents from performing mathematically impossible operations.

``` bash
    Allowed: Adding 10_hz to 440_hz.
    Blocked: Adding 440_hz to -6_db. 
    If you try to mix these up, the code will fail to compile and you will see an error message: "ONYX ERROR: Cannot convert between different dimensions!"
``` 
- It Handles Unit Scaling Automatically
    The conversion function uses std::ratio to handle metric prefixes like kilo (103) or milli (10−3).
    It calculates a factor based on the numerator and denominator of the units.
    This allows you to write onyx::convert 
    Eg: onyx::Hz (1_khz) and get 1000.0 without manually typing (somevalue* 1000.)

-  It Provides "Syntax Sugar" which makes the code easier to understand<br>
    That is: Instead of double freq = 440;, you write auto freq = 440_hz.