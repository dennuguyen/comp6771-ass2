///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector multiply friend function.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Dimension of product should be same as multiplicand") {
	SECTION("Empty euclidean vectors") {
		auto const mult = comp6771::euclidean_vector(0);
		auto const prod = mult * 3;
		CHECK(prod.dimensions() == 0);
	}

	SECTION("Zero euclidean vectors") {
		auto const mult = comp6771::euclidean_vector(100, 0.0);
		auto const diff = mult * 3;
		CHECK(diff.dimensions() == 100);
	}
}

TEST_CASE("Multiplicand and multiplier should return product with multiplied components") {
	SECTION("Zero multiplicand") {
		auto const mult = comp6771::euclidean_vector({0.0, 0.0, 0.0, 0.0, 0.0, 0.0});
		auto const prod = mult * 30;
		CHECK(prod.at(0) == Approx(0.0));
		CHECK(prod.at(1) == Approx(0.0));
		CHECK(prod.at(2) == Approx(0.0));
		CHECK(prod.at(3) == Approx(0.0));
		CHECK(prod.at(4) == Approx(0.0));
		CHECK(prod.at(5) == Approx(0.0));
		CHECK(prod.dimensions() == 6);
	}

	SECTION("Zero multiplier") {
		auto const mult = comp6771::euclidean_vector({6.2, -0.43, 432.1, -0.4382, 43.210, 432.56});
		auto const prod = mult * 0;
		CHECK(prod.at(0) == Approx(0.0));
		CHECK(prod.at(1) == Approx(0.0));
		CHECK(prod.at(2) == Approx(0.0));
		CHECK(prod.at(3) == Approx(0.0));
		CHECK(prod.at(4) == Approx(0.0));
		CHECK(prod.at(5) == Approx(0.0));
		CHECK(prod.dimensions() == 6);
	}

	SECTION("Positive multiplier") {
		auto const mult = comp6771::euclidean_vector({6.2, -0.43, 432.1, -0.4382, 43.210, 432.56});
		auto const prod = mult * 3.4;
		CHECK(prod.at(0) == Approx(21.08));
		CHECK(prod.at(1) == Approx(-1.462));
		CHECK(prod.at(2) == Approx(1469.14));
		CHECK(prod.at(3) == Approx(-1.48988));
		CHECK(prod.at(4) == Approx(146.914));
		CHECK(prod.at(5) == Approx(1470.704));
		CHECK(prod.dimensions() == 6);
	}

	SECTION("Negative multiplier") {
		auto const mult = comp6771::euclidean_vector({6.2, -0.43, 432.1, -0.4382, 43.210, 432.56});
		auto const prod = mult * -3.4;
		CHECK(prod.at(0) == Approx(-21.08));
		CHECK(prod.at(1) == Approx(1.462));
		CHECK(prod.at(2) == Approx(-1469.14));
		CHECK(prod.at(3) == Approx(1.48988));
		CHECK(prod.at(4) == Approx(-146.914));
		CHECK(prod.at(5) == Approx(-1470.704));
		CHECK(prod.dimensions() == 6);
	}
}

TEST_CASE("Swapping order of multiplier and multiplicand should have no effect") {
	SECTION("Euclidean vectors with some positive and negative components") {
		auto const mult = comp6771::euclidean_vector({3.3, 5.3, -2.3});
		auto const prod1 = mult * 2;
		auto const prod2 = 2 * mult;

		CHECK(prod1.at(0) == Approx(6.6));
		CHECK(prod1.at(1) == Approx(10.6));
		CHECK(prod1.at(2) == Approx(-4.6));
		CHECK(prod1.dimensions() == 3);

		CHECK(prod2.at(0) == Approx(6.6));
		CHECK(prod2.at(1) == Approx(10.6));
		CHECK(prod2.at(2) == Approx(-4.6));
		CHECK(prod2.dimensions() == 3);
	}
}

TEST_CASE("Multiplying euclidean vector should not modify multiplicand and multiplier") {
	SECTION("Euclidean vectors with some positive and negative components") {
		auto mult = comp6771::euclidean_vector({3.3, 5.3, -2.3, 0.0});
		auto val = 4.2;
		mult* val;

		CHECK(mult.at(0) == Approx(3.3));
		CHECK(mult.at(1) == Approx(5.3));
		CHECK(mult.at(2) == Approx(-2.3));
		CHECK(mult.at(3) == Approx(0.0));
		CHECK(mult.dimensions() == 4);

		CHECK(val == Approx(4.2));
	}
}
