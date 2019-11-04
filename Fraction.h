#pragma once

#include "pch.h"

class Fraction;

// Linker can't find friend functions otherwise
constexpr Fraction operator+(const Fraction& lhs, const Fraction& rhs);
constexpr Fraction operator-(const Fraction& lhs, const Fraction& rhs);
constexpr Fraction operator*(const Fraction& lhs, const Fraction& rhs);

class Fraction
{
public:
	explicit constexpr Fraction(const int numerator, const int denominator) :
		num_(numerator), denom_(denominator)
	{
		assert(denominator != 0);
	}
	constexpr Fraction(const int numerator) :
		num_(numerator), denom_(1)
	{}

	// Arithmetic operators

	constexpr friend Fraction operator+(
		const Fraction& lhs, const Fraction& rhs);

	constexpr friend Fraction operator-(
		const Fraction& lhs, const Fraction& rhs);

	constexpr friend Fraction operator*(
		const Fraction& lhs, const Fraction& rhs);

	// Equality operators
	friend bool operator==(const Fraction& lhs, const Fraction& rhs)
	{
		return lhs.num_ == rhs.num_ && lhs.denom_ == rhs.denom_;
	}

	friend bool operator!=(const Fraction& lhs, const Fraction& rhs)
	{
		return !(lhs == rhs);
	}

	// Stream operator
	friend std::ostream& operator<<(std::ostream& os, const Fraction& obj);

private:
	// Simplifies the fractional expression
	void simplify();

	int num_;
	int denom_;
};