///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector subtraction friend function.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Dimension of difference should be same as minuend and subtrahend") {
	SECTION("Empty euclidean vectors") {
		auto const lhs = comp6771::euclidean_vector(0);
		auto const rhs = comp6771::euclidean_vector(0);
		auto const diff = lhs - rhs;
		CHECK(diff.dimensions() == 0);
	}

	SECTION("Zero euclidean vectors") {
		auto const lhs = comp6771::euclidean_vector(100, 0.0);
		auto const rhs = comp6771::euclidean_vector(100, 0.0);
		auto const diff = lhs - rhs;
		CHECK(diff.dimensions() == 100);
	}
}

TEST_CASE("Subtracting euclidean vectors should return euclidean vector with subtracted "
          "components") {
	SECTION("Zero minuend") {
		auto const lhs = comp6771::euclidean_vector({0.0, 0.0, 0.0, 0.0, 0.0, 0.0});
		auto const rhs = comp6771::euclidean_vector({6.2, -0.43, 432.1, -0.4382, 43.210, 432.56});
		auto const diff = lhs - rhs;
		CHECK(diff.at(0) == Approx(-6.2));
		CHECK(diff.at(1) == Approx(0.43));
		CHECK(diff.at(2) == Approx(-432.1));
		CHECK(diff.at(3) == Approx(0.4382));
		CHECK(diff.at(4) == Approx(-43.210));
		CHECK(diff.at(5) == Approx(-432.56));
		CHECK(diff.dimensions() == 6);
	}

	SECTION("Zero subtrahend") {
		auto const lhs = comp6771::euclidean_vector({6.2, -0.43, 432.1, -0.4382, 43.210, 432.56});
		auto const rhs = comp6771::euclidean_vector({0.0, 0.0, 0.0, 0.0, 0.0, 0.0});
		auto const diff = lhs - rhs;
		CHECK(diff.at(0) == Approx(6.2));
		CHECK(diff.at(1) == Approx(-0.43));
		CHECK(diff.at(2) == Approx(432.1));
		CHECK(diff.at(3) == Approx(-0.4382));
		CHECK(diff.at(4) == Approx(43.210));
		CHECK(diff.at(5) == Approx(432.56));
		CHECK(diff.dimensions() == 6);
	}

	SECTION("Euclidean vector subtracting itself") {
		auto const lhs = comp6771::euclidean_vector({6.2, -0.43, 432.1, -0.4382, 43.210, 432.56});
		auto const rhs = comp6771::euclidean_vector({6.2, -0.43, 432.1, -0.4382, 43.210, 432.56});
		auto const diff = lhs - rhs;
		CHECK(diff.at(0) == Approx(0.0));
		CHECK(diff.at(1) == Approx(0.0));
		CHECK(diff.at(2) == Approx(0.0));
		CHECK(diff.at(3) == Approx(0.0));
		CHECK(diff.at(4) == Approx(0.0));
		CHECK(diff.at(5) == Approx(0.0));
		CHECK(diff.dimensions() == 6);
	}

	SECTION("Euclidean vectors with some positive and negative components") {
		auto const lhs = comp6771::euclidean_vector({0.5, 0.6, 0.7});
		auto const rhs = comp6771::euclidean_vector({-0.2, -0.8, 1.2});
		auto const diff = lhs - rhs;
		CHECK(diff.at(0) == Approx(0.7));
		CHECK(diff.at(1) == Approx(1.4));
		CHECK(diff.at(2) == Approx(-0.5));
		CHECK(diff.dimensions() == 3);
	}
}

TEST_CASE("Swapping minuend and subtrahend should return euclidean vector and its negation") {
	SECTION("Euclidean vectors with some positive and negative components") {
		auto const lhs = comp6771::euclidean_vector({3.3, 5.3, -2.3});
		auto const rhs = comp6771::euclidean_vector({8.4, -0.32, 2.1});
		auto const diff1 = lhs - rhs;
		auto const diff2 = rhs - lhs;

		CHECK(diff1.at(0) == Approx(-5.1));
		CHECK(diff1.at(1) == Approx(5.62));
		CHECK(diff1.at(2) == Approx(-4.4));
		CHECK(diff1.dimensions() == 3);

		CHECK(diff2.at(0) == Approx(5.1));
		CHECK(diff2.at(1) == Approx(-5.62));
		CHECK(diff2.at(2) == Approx(4.4));
		CHECK(diff2.dimensions() == 3);
	}
}

TEST_CASE("Subtracting euclidean vectors should not modify minuend and subtrahend") {
	SECTION("Euclidean vectors with some positive and negative components") {
		auto lhs = comp6771::euclidean_vector({3.3, 5.3, -2.3});
		auto rhs = comp6771::euclidean_vector({8.4, -0.32, 2.1});
		lhs - rhs;

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
		auto const lhs = comp6771::euclidean_vector(3);
		auto const rhs = comp6771::euclidean_vector(4);
		CHECK_THROWS_AS(lhs - rhs, comp6771::euclidean_vector_error);
	}

	SECTION("Dimension of LHS is greater than RHS") {
		auto const lhs = comp6771::euclidean_vector(10);
		auto const rhs = comp6771::euclidean_vector(9);
		CHECK_THROWS_AS(lhs - rhs, comp6771::euclidean_vector_error);
	}
}
