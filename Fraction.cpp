// Fraction.cpp : Defines the functions for the Fraction-class.
//

#include "pch.h"
#include "Fraction.h"

Fraction operator+(const Fraction& lhs, const Fraction& rhs) noexcept
{
	const auto new_num = lhs.num_ * rhs.denom_ + rhs.num_ * lhs.denom_;
	
	return Fraction(new_num ,lhs.denom_ * rhs.denom_);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) noexcept
{
	const auto new_num = lhs.num_ * rhs.denom_ - rhs.num_ * lhs.denom_;

	return Fraction(new_num, lhs.denom_ * rhs.denom_);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) noexcept
{
	const auto new_num = lhs.num_ * rhs.num_;
	const auto new_denom = lhs.denom_ * rhs.denom_;

	// Constructor simplifies the expression
	return Fraction(new_num, new_denom);
}

Fraction& operator+=(Fraction& lhs, const Fraction& rhs) noexcept
{
	lhs.num_ = lhs.num_ * rhs.denom_ + rhs.num_ * lhs.denom_;
	lhs.denom_ *= rhs.denom_;

	lhs.simplify();
	return lhs;
}

Fraction& operator-=(Fraction& lhs, const Fraction& rhs) noexcept
{
	lhs.num_ = lhs.num_ * rhs.denom_ - rhs.num_ * lhs.denom_;
	lhs.denom_ *= rhs.denom_;

	lhs.simplify();
	return lhs;
}

Fraction& operator*=(Fraction& lhs, const Fraction& rhs) noexcept
{
	lhs.num_ *= rhs.num_;
	lhs.denom_ *= rhs.denom_;

	lhs.simplify();
	return lhs;
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.denom_ == 1)
	{
		// Return as an integer
		return os << obj.num_;
	}
	return os << obj.num_ << "/" << obj.denom_;
}

void Fraction::simplify() noexcept
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