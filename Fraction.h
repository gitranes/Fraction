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
	constexpr Fraction(const int numerator) :
		num_(numerator), denom_(1)
	{}

	
	// Arithmetic operators.
	
	friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
	friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);

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