// Fraction.cpp : Defines the functions for the Fraction-class.
//

#include "pch.h"
#include "Fraction.h"

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