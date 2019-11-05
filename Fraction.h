#pragma once

#include "pch.h"

class Fraction
{
public:
	// Default constructor initializes to 0
	Fraction() noexcept : num_(0), denom_(1)
	{}
	
	explicit Fraction(const int numerator, const int denominator) :
		num_(numerator), denom_(denominator)
	{
		assert(denominator != 0);
		simplify();
	}
	constexpr Fraction(const int numerator) noexcept :
		num_(numerator), denom_(1)
	{}

	// Reciprocal constructor
	constexpr Fraction(const int numerator, const Fraction fraction) :
		num_(numerator * fraction.denom_), denom_(fraction.num_)
	{}

	// Can be cast to int when denom_ is one
	explicit constexpr operator int() const
	{
		assert(denom_ == 1);
		return int(num_);
	}

	// Casts to floating points
	explicit constexpr operator float() const
	{
		return float( static_cast<float>(num_) / static_cast<float>(denom_));
	}

	explicit constexpr operator double() const
	{
		return double( static_cast<double>(num_) / denom_);
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

	// Relational operators

	friend bool operator<(const Fraction& lhs, const Fraction& rhs)
	{
		return static_cast<double>(lhs) < static_cast<double>(rhs);
	}

	friend bool operator<=(const Fraction& lhs, const Fraction& rhs)
	{
		return !(rhs < lhs);
	}

	friend bool operator>(const Fraction& lhs, const Fraction& rhs)
	{
		return rhs < lhs;
	}

	friend bool operator>=(const Fraction& lhs, const Fraction& rhs)
	{
		return !(lhs < rhs);
	}

	// Stream operator
	friend std::ostream& operator<<(std::ostream& os, const Fraction& obj);

private:
	// Simplifies the fractional expression
	void simplify() noexcept;

	int num_;
	int denom_;
};