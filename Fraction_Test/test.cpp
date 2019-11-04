#include "pch.h"
#include "Fraction.h"

namespace FractionTest
{
	class FractionTest : public ::testing::Test
	{
	public:
		FractionTest() = default;

	protected:
		Fraction half_{ 1, 2 };
		Fraction quarter_{ 1, 4 };
		Fraction one_sixth_{ 1, 6 };
	};

	TEST_F(FractionTest, ConstructTest)
	{
		Fraction half(2, 4);
		ASSERT_EQ(half, half_);

		Fraction quarter(2, 8);
		ASSERT_EQ(quarter, quarter_);

		ASSERT_DEATH(Fraction(1, 0), "^Assertion failed");

		using rhalf = std::ratio<1, 2>;
		using rhalf2 = std::ratio<1, 2>;
	}

	TEST_F(FractionTest, SumTest)
	{	
		const auto half = half_;
		const auto one = half + half_;
		ASSERT_EQ(1, one);

		const auto quarter = quarter_;
		const auto half2 = quarter + quarter_;
		ASSERT_EQ(half, half2);

		const Fraction one_third(1, 3);
		const auto half3 = one_third + one_sixth_;
		ASSERT_EQ(half, half3);
	}

	TEST_F(FractionTest, SubTest)
	{
		const auto half = half_;
		const auto zero = half - half_;
		ASSERT_EQ(0, zero);

		const auto quarter = half - quarter_;
		ASSERT_EQ(quarter, quarter_);
	}


	TEST_F(FractionTest, ProductTest)
	{
		const auto half = half_;
		const auto quarter = half * half_;
		ASSERT_EQ(quarter_, quarter);

		const auto quarter2 = quarter_;
		const auto one_sixteenth = quarter * quarter_;
		ASSERT_EQ(one_sixteenth, Fraction(1, 16));

		Fraction one(1);
		const auto half2 = 1 * half;
		ASSERT_EQ(half, half2);
}
}