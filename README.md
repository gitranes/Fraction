# Fraction
C++ Fraction library with Google unit-tests

## Basic usage
Here is a basic example how one could you the Fraction class. The Fraction is always kept as simplified as possible eg.
2/4 is represented as 1/2 etc.
```cpp
Fraction half(1, 2);

auto one = half + half;
std::cout << half << " + " << another_half << " = " << one << std::endl;
// Prints out: 1/2 + 1/2 = 1

auto quarter = half * half
std::cout << quarter << std::endl;

// Prints out: 1/4

// Reciprocal constructor eg. 1/4 -> 4/1
auto four = Fraction(1, quarter);
auto two = Fraction(1, half);
```

## Explicit conversions
Fraction class provides explicit conversions for `double` and `float`. `int` can also be explicitly converted if the denominator of the Fraction is 1 (Rounding conversions are not allowed).
```cpp
Fraction half(1, 2);
Fraction one(1);

auto d_half = static_cast<double>(half);

// Fraction can also be cast back to int, if the denominator is 1
auto one = static_cast<int>(one);

// Assertion failure: Rounding conversions are not allowed. 
auto half = static_cast<int>(half);
```
## Constexpr usage
For constexpr fractions see `std::ratio` that has been available since C++11. This Fraction class provides only constexpr construction from a whole number literal.
```cpp
constexpr Fraction one(1);
```
