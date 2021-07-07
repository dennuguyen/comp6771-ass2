///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector addition friend function.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Adding euclidean vectors should return euclidean vector with added components") {
	SECTION("Empty euclidean vectors") {
		auto const lhs = comp6771::euclidean_vector(0);
		auto const rhs = comp6771::euclidean_vector(0);
		auto const sum = lhs + rhs;
		CHECK(sum.dimensions() == 0);
	}

	SECTION("Zero euclidean vectors") {
		auto const lhs = comp6771::euclidean_vector(100, 0.0);
		auto const rhs = comp6771::euclidean_vector(100, 0.0);
		auto const sum = lhs + rhs;
		CHECK(sum.dimensions() == 100);
	}

	SECTION("Euclidean vectors with some positive and negative components") {
		auto const lhs = comp6771::euclidean_vector({6.2, -0.43, 432.1, -0.4382, 43.210, 432.56});
		auto const rhs = comp6771::euclidean_vector({6.2, -0.43, 432.1, -0.4382, 43.210, 432.56});
		auto const sum = lhs + rhs;
		CHECK(sum.at(0) == Approx(12.4));
		CHECK(sum.at(1) == Approx(-0.86));
		CHECK(sum.at(2) == Approx(864.2));
		CHECK(sum.at(3) == Approx(-0.8764));
		CHECK(sum.at(4) == Approx(86.42));
		CHECK(sum.at(5) == Approx(865.12));
		CHECK(sum.dimensions() == 6);
	}
}

TEST_CASE("LHS and RHS addend order should not change sum") {
	SECTION("Euclidean vectors with some positive and negative components") {
		auto const lhs = comp6771::euclidean_vector({3.3, 5.3, -2.3});
		auto const rhs = comp6771::euclidean_vector({8.4, -0.32, 2.1});
		auto const sum1 = lhs + rhs;
		auto const sum2 = rhs + lhs;

		CHECK(sum1.at(0) == Approx(11.7));
		CHECK(sum1.at(1) == Approx(4.98));
		CHECK(sum1.at(2) == Approx(-0.2));
		CHECK(sum1.dimensions() == 3);

		CHECK(sum2.at(0) == Approx(11.7));
		CHECK(sum2.at(1) == Approx(4.98));
		CHECK(sum2.at(2) == Approx(-0.2));
		CHECK(sum2.dimensions() == 3);
	}
}

TEST_CASE("Adding euclidean vectors should not modify addends") {
	SECTION("Euclidean vectors with some positive and negative components") {
		auto lhs = comp6771::euclidean_vector({3.3, 5.3, -2.3});
		auto rhs = comp6771::euclidean_vector({8.4, -0.32, 2.1});
		lhs + rhs;

		CHECK(lhs.at(0) == Approx(3.3));
		CHECK(lhs.at(1) == Approx(5.3));
		CHECK(lhs.at(2) == Approx(-2.3));
		CHECK(lhs.dimensions() == 3);

		CHECK(rhs.at(0) == Approx(8.4));
		CHECK(rhs.at(1) == Approx(-0.32));
		CHECK(rhs.at(2) == Approx(2.1));
		CHECK(rhs.dimensions() == 3);
	}
}

TEST_CASE("Different LHS and RHS dimensions should throw") {
	SECTION("Dimension of LHS is less than RHS") {
		auto const lhs = comp6771::euclidean_vector(4);
		auto const rhs = comp6771::euclidean_vector(5);
		CHECK_THROWS_AS(lhs + rhs, comp6771::euclidean_vector_error);
	}

	SECTION("Dimension of LHS is greater than RHS") {
		auto const lhs = comp6771::euclidean_vector(6);
		auto const rhs = comp6771::euclidean_vector(5);
		CHECK_THROWS_AS(lhs + rhs, comp6771::euclidean_vector_error);
	}
}
