# Onyx.h 

It is a lightweight C++20 library designed for Compile-Time Unit Conversions. 
It is built specifically for high-performance audio applications like Digital Signal Processors where mixing up Frequencies and Amplitude which might lead into runtime errors and is hard to debug.

##  Features

* **All unit validation is performed at compile-time.**
* **Clean and readable syntax.**
* **Just use `onyx.h` in your project and you can use it.**

## How to Use??
Just copy `onyx.h` into your project's include directory.

### Basic Use
```cpp
#include "onyx.h"

using namespace onyx::literals;

int main() {
    auto sRate = 44100_hz;
    auto lat    = 10.5_ms;
    auto v     = -3.0_db;
    auto nRate = sRate + 100_hz;
    return 0;
}
```