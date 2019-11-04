#pragma once

#include "pch.h"

class Fraction
{
public:
	explicit Fraction(const int numerator, const int denominator) :
		num_(numerator), denom_(denominator)
	{
		assert(denominator != 0);
		simplify();
	}
	constexpr Fraction(const int numerator) noexcept :
		num_(numerator), denom_(1)
	{}

	// Can be cast to int when denom_ is one
	explicit constexpr operator int() const
	{
		assert(denom_ == 1);
		return int(num_);
	}

	// Arithmetic operators. Even though the non-assigning operators call
	// the constructor with the assert, that assert can never be triggered,
	// hence the operators are noexcept.
	
	friend Fraction operator+(const Fraction& lhs, const Fraction& rhs) noexcept;
	friend Fraction operator-(const Fraction& lhs, const Fraction& rhs) noexcept;
	friend Fraction operator*(const Fraction& lhs, const Fraction& rhs) noexcept;
	friend Fraction& operator+=(Fraction& lhs, const Fraction& rhs) noexcept;
	friend Fraction& operator-=(Fraction& lhs, const Fraction& rhs) noexcept;
	friend Fraction& operator*=(Fraction& lhs, const Fraction& rhs) noexcept;

	// Equality operators
	friend bool operator==(const Fraction& lhs, const Fraction& rhs) noexcept
	{
		return lhs.num_ == rhs.num_ && lhs.denom_ == rhs.denom_;
	}

	friend bool operator!=(const Fraction& lhs, const Fraction& rhs) noexcept
	{
		return !(lhs == rhs);
	}

	// Stream operator
	friend std::ostream& operator<<(std::ostream& os, const Fraction& obj);

private:
	// Simplifies the fractional expression
	void simplify() noexcept;

	int num_;
	int denom_;
};