// Fraction.cpp : Defines the functions for the Fraction-class.
//

#include "pch.h"
#include "Fraction.h"

constexpr Fraction operator+(const Fraction& lhs, const Fraction& rhs)
{
	// least common multiple
	const auto lcd = std::lcm(lhs.denom_, rhs.denom_);

	const auto new_lhs = lcd * lhs;
	const auto new_rhs = lcd * rhs;

	const auto new_num = new_lhs.num_ + new_rhs.num_;

	return Fraction(new_num, new_lhs.denom_);
}

constexpr Fraction operator-(const Fraction& lhs, const Fraction& rhs)
{
	// least common multiple
	const auto lcd = std::lcm(lhs.denom_, rhs.denom_);

	const auto new_lhs = lcd * lhs;
	const auto new_rhs = lcd * rhs;

	const auto new_num = new_lhs.num_ - new_rhs.num_;

	return Fraction(new_num, new_lhs.denom_);
}

constexpr Fraction operator*(const Fraction& lhs, const Fraction& rhs)
{
	const auto new_num = lhs.num_ * rhs.num_;
	const auto new_denom = lhs.denom_ * rhs.denom_;

	// Constructor simplifies the expression
	return Fraction(new_num, new_denom);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	return os << obj.num_ << "/" << obj.denom_ << std::endl;
}


void Fraction::simplify()
{
	// Determine the sign of the Fraction
	const auto sign_num = num_ < 0 ? -1 : 1;
	const auto sign_denom = denom_ < 0 ? -1 : 1;
	const auto sign = sign_num * sign_denom;

	// Greatest common divisor
	const auto gcd = std::gcd(num_, denom_);

	denom_ = abs(denom_) / gcd;
	num_ = sign * abs(num_) / gcd;
}