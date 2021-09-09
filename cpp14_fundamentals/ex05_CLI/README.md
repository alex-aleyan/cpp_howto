### C++ Preprocessor, Constants, and Constant Expressions:
- review const.h file and helloworld.cpp
- In C++, we don't use ```#define``` unless we have to - use ```const``` or ```constexpr``` instead. It's okay to use ```#define``` as **include guards** but ```#pragma once``` is a more popular choice.
- Since constexpr is handled by the preprocessor. A variable declared as constexpr may not be modified during the runtime.

