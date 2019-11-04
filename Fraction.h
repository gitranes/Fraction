#pragma once

#include "pch.h"

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

	// Arithmetic operators. constexpr are implicitly inline

	constexpr friend Fraction operator+(
		const Fraction& lhs, const Fraction& rhs)
	{
		// least common multiple
		const auto lcd = std::lcm(lhs.denom_, rhs.denom_);

		const auto new_lhs = lcd * lhs;
		const auto new_rhs = lcd * rhs;

		const auto new_num = new_lhs.num_ + new_rhs.num_;

		return Fraction(new_num, new_lhs.denom_);
	}

	constexpr friend Fraction operator-(
		const Fraction& lhs, const Fraction& rhs)
	{
		// least common multiple
		const auto lcd = std::lcm(lhs.denom_, rhs.denom_);

		const auto new_lhs = lcd * lhs;
		const auto new_rhs = lcd * rhs;

		const auto new_num = new_lhs.num_ - new_rhs.num_;

		return Fraction(new_num, new_lhs.denom_);
	}

	constexpr friend Fraction operator*(
		const Fraction& lhs, const Fraction& rhs)
	{
		const auto new_num = lhs.num_ * rhs.num_;
		const auto new_denom = lhs.denom_ * rhs.denom_;

		// Constructor simplifies the expression
		return Fraction(new_num, new_denom);
	}

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