///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector divide friend function.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Dimension of product should be same as dividend") {
	SECTION("Empty euclidean vectors") {
		auto const div = comp6771::euclidean_vector(0);
		auto const quot = div / 3;
		CHECK(quot.dimensions() == 0);
	}

	SECTION("Zero euclidean vectors") {
		auto const div = comp6771::euclidean_vector(100, 0.0);
		auto const quot = div / 3;
		CHECK(quot.dimensions() == 100);
	}
}

TEST_CASE("Dividend and divisor should return quotient with divised components") {
	SECTION("Zero dividend") {
		auto const div = comp6771::euclidean_vector({0.0, 0.0, 0.0, 0.0, 0.0, 0.0});
		auto const quot = div / 12.3;
		CHECK(quot.at(0) == Approx(0.0));
		CHECK(quot.at(1) == Approx(0.0));
		CHECK(quot.at(2) == Approx(0.0));
		CHECK(quot.at(3) == Approx(0.0));
		CHECK(quot.at(4) == Approx(0.0));
		CHECK(quot.at(5) == Approx(0.0));
		CHECK(quot.dimensions() == 6);
	}

	SECTION("Positive divisor") {
		auto const div = comp6771::euclidean_vector({6.2, -0.43, 432.1, -0.4382, 43.210, 432.56});
		auto const quot = div / 3.4;
		CHECK(quot.at(0) == Approx(1.823529));
		CHECK(quot.at(1) == Approx(-0.12647));
		CHECK(quot.at(2) == Approx(127.088235));
		CHECK(quot.at(3) == Approx(-0.12888235));
		CHECK(quot.at(4) == Approx(12.70882));
		CHECK(quot.at(5) == Approx(127.223529));
		CHECK(quot.dimensions() == 6);
	}

	SECTION("Negative divisor") {
		auto const div = comp6771::euclidean_vector({6.2, -0.43, 432.1, -0.4382, 43.210, 432.56});
		auto const quot = div / -3.4;
		CHECK(quot.at(0) == Approx(-1.823529));
		CHECK(quot.at(1) == Approx(0.12647));
		CHECK(quot.at(2) == Approx(-127.088235));
		CHECK(quot.at(3) == Approx(0.12888235));
		CHECK(quot.at(4) == Approx(-12.70882));
		CHECK(quot.at(5) == Approx(-127.223529));
		CHECK(quot.dimensions() == 6);
	}
}

TEST_CASE("Dividing euclidean vector should not modify dividend and divisor") {
	SECTION("Euclidean vectors with some positive and negative components") {
		auto div = comp6771::euclidean_vector({3.3, 5.3, -2.3, 0.0});
		auto val = 4.2;
		div / val;

		CHECK(div.at(0) == Approx(3.3));
		CHECK(div.at(1) == Approx(5.3));
		CHECK(div.at(2) == Approx(-2.3));
		CHECK(div.at(3) == Approx(0.0));
		CHECK(div.dimensions() == 4);

		CHECK(val == Approx(4.2));
	}
}

TEST_CASE("Division by zero should throw") {
	SECTION("Positive zero") {
		auto const div = comp6771::euclidean_vector({1, 2, 3});
		CHECK_THROWS_AS(div / 0.0, comp6771::euclidean_vector_error);
	}

	SECTION("Negative zero") {
		auto const div = comp6771::euclidean_vector({1, 2, 3});
		CHECK_THROWS_AS(div / -0.0, comp6771::euclidean_vector_error);
	}
}
