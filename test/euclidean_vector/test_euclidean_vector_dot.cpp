///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector dot product utility function.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Dot product of euclidean vectors should multiply components element-wise and sum them") {
	SECTION("Empty vector") {
		auto const lhs = comp6771::euclidean_vector({});
		auto const rhs = comp6771::euclidean_vector({});
		auto const dot = comp6771::dot(lhs, rhs);
		CHECK(dot == Approx(0));
	}

	SECTION("Zero vector") {
		auto const lhs = comp6771::euclidean_vector(5);
		auto const rhs = comp6771::euclidean_vector(5);
		auto const dot = comp6771::dot(lhs, rhs);
		CHECK(dot == Approx(0));
	}

	SECTION("Euclidean vector with some positive and negative components") {
		auto const lhs = comp6771::euclidean_vector({4.1, 3.2, -0.54, -5.9});
		auto const rhs = comp6771::euclidean_vector({-6.7, 4.3, 7.9, 5.1});
		auto const dot = comp6771::dot(lhs, rhs);
		CHECK(dot == Approx(-48.066));
	}
}

TEST_CASE("Dot product should not modify inputted euclidean vectors") {
	SECTION("Euclidean vector with some positive and negative components") {
		auto lhs = comp6771::euclidean_vector({4.1, 3.2, -0.54, -5.9});
		auto rhs = comp6771::euclidean_vector({-6.7, 4.3, 7.9, 5.1});
		comp6771::dot(lhs, rhs);

		CHECK(lhs.at(0) == Approx(4.1));
		CHECK(lhs.at(1) == Approx(3.2));
		CHECK(lhs.at(2) == Approx(-0.54));
		CHECK(lhs.at(3) == Approx(-5.9));
		CHECK(lhs.dimensions() == 4);

		CHECK(rhs.at(0) == Approx(-6.7));
		CHECK(rhs.at(1) == Approx(4.3));
		CHECK(rhs.at(2) == Approx(7.9));
		CHECK(rhs.at(3) == Approx(5.1));
		CHECK(rhs.dimensions() == 4);
	}
}

TEST_CASE("Swapping order of dot product should not change result") {
	SECTION("Euclidean vector with some positive and negative components") {
		auto const lhs = comp6771::euclidean_vector({9.415, -0.953, -50.54, -25.409});
		auto const rhs = comp6771::euclidean_vector({-569.07, 94.434, 37.3429, 542.1123});
		auto const dot1 = comp6771::dot(lhs, rhs);
		auto const dot2 = comp6771::dot(rhs, lhs);
		CHECK(dot1 == Approx(-21109.63125));
		CHECK(dot2 == Approx(-21109.63125));
	}
}

TEST_CASE("Dot product of euclidean vectors with different dimensions should throw") {
	SECTION("Dimension of LHS is greater than RHS") {
		auto const lhs = comp6771::euclidean_vector(3);
		auto const rhs = comp6771::euclidean_vector(1);
		CHECK_THROWS_AS(comp6771::dot(lhs, rhs), comp6771::euclidean_vector_error);
	}

	SECTION("Dimension of LHS is less than RHS") {
		auto const lhs = comp6771::euclidean_vector(12);
		auto const rhs = comp6771::euclidean_vector(19);
		CHECK_THROWS_AS(comp6771::dot(lhs, rhs), comp6771::euclidean_vector_error);
	}
}