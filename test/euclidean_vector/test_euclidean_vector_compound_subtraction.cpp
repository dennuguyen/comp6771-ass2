///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector compound subtraction operator.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Compound subtraction should subtract RHS magnitude from LHS magnitudes") {
	SECTION("Subtracting empty RHS from empty LHS") {
		auto lhs = comp6771::euclidean_vector({});
		auto const rhs = comp6771::euclidean_vector({});
		lhs -= rhs;
		CHECK(lhs.dimensions() == 0);
	}

	SECTION("Subtracting zero RHS from LHS") {
		auto lhs = comp6771::euclidean_vector({2.3, 4.6, 1.1});
		auto const rhs = comp6771::euclidean_vector({0.0, 0.0, 0.0});
		lhs -= rhs;
		CHECK(lhs.at(0) == Approx(2.3));
		CHECK(lhs.at(1) == Approx(4.6));
		CHECK(lhs.at(2) == Approx(1.1));
		CHECK(lhs.dimensions() == 3);
	}

	SECTION("Subtracting RHS from zero LHS") {
		auto lhs = comp6771::euclidean_vector({0.0, 0.0, 0.0, 0.0});
		auto const rhs = comp6771::euclidean_vector({4.33, 43.612, 95.1, 213.1});
		lhs -= rhs;
		CHECK(lhs.at(0) == Approx(-4.33));
		CHECK(lhs.at(1) == Approx(-43.612));
		CHECK(lhs.at(2) == Approx(-95.1));
		CHECK(lhs.at(3) == Approx(-213.1));
		CHECK(lhs.dimensions() == 4);
	}

	SECTION("Subtracting RHS with positive components from LHS with positive components") {
		auto lhs = comp6771::euclidean_vector({9.4, 1.43, 1.1});
		auto const rhs = comp6771::euclidean_vector({2.3, 4.6, 1.1});
		lhs -= rhs;
		CHECK(lhs.at(0) == Approx(7.1));
		CHECK(lhs.at(1) == Approx(-3.17));
		CHECK(lhs.at(2) == Approx(0.0));
		CHECK(lhs.dimensions() == 3);
	}

	SECTION("Subtracting RHS with negative components from LHS with positive components") {
		auto lhs = comp6771::euclidean_vector({1.42, 1.2, 4.63});
		auto const rhs = comp6771::euclidean_vector({-2.3, -4.6, -1.1});
		lhs -= rhs;
		CHECK(lhs.at(0) == Approx(3.72));
		CHECK(lhs.at(1) == Approx(5.8));
		CHECK(lhs.at(2) == Approx(5.73));
		CHECK(lhs.dimensions() == 3);
	}

	SECTION("Subtracting RHS with positive components from LHS with negative components") {
		auto lhs = comp6771::euclidean_vector({-1.42, -1.2, -4.63});
		auto const rhs = comp6771::euclidean_vector({2.3, 4.6, 1.1});
		lhs -= rhs;
		CHECK(lhs.at(0) == Approx(-3.72));
		CHECK(lhs.at(1) == Approx(-5.8));
		CHECK(lhs.at(2) == Approx(-5.73));
		CHECK(lhs.dimensions() == 3);
	}

	SECTION("Subtracting RHS with negative components from LHS with negative components") {
		auto lhs = comp6771::euclidean_vector({-1.42, -1.2, -4.63});
		auto const rhs = comp6771::euclidean_vector({-2.3, -4.6, -1.1});
		lhs -= rhs;
		CHECK(lhs.at(0) == Approx(0.88));
		CHECK(lhs.at(1) == Approx(3.4));
		CHECK(lhs.at(2) == Approx(-3.53));
		CHECK(lhs.dimensions() == 3);
	}
}

TEST_CASE("Compound subtraction should not change RHS") {
	SECTION("Subtracting empty RHS from empty LHS") {
		auto lhs = comp6771::euclidean_vector({});
		auto rhs = comp6771::euclidean_vector({});
		lhs -= rhs;
		CHECK(rhs.dimensions() == 0);
	}

	SECTION("Subtracting zero RHS from LHS") {
		auto lhs = comp6771::euclidean_vector({2.3, 4.6, 1.1});
		auto rhs = comp6771::euclidean_vector({0.0, 0.0, 0.0});
		lhs -= rhs;
		CHECK(rhs.at(0) == Approx(0.0));
		CHECK(rhs.at(1) == Approx(0.0));
		CHECK(rhs.at(2) == Approx(0.0));
		CHECK(rhs.dimensions() == 3);
	}

	SECTION("Subtracting RHS from zero LHS") {
		auto lhs = comp6771::euclidean_vector({0.0, 0.0, 0.0, 0.0});
		auto rhs = comp6771::euclidean_vector({4.33, 43.612, 95.1, 213.1});
		lhs -= rhs;
		CHECK(rhs.at(0) == Approx(4.33));
		CHECK(rhs.at(1) == Approx(43.612));
		CHECK(rhs.at(2) == Approx(95.1));
		CHECK(rhs.at(3) == Approx(213.1));
		CHECK(rhs.dimensions() == 4);
	}

	SECTION("Subtracting RHS with positive components from LHS with positive components") {
		auto lhs = comp6771::euclidean_vector({9.4, 1.43, 1.1});
		auto rhs = comp6771::euclidean_vector({2.3, 4.6, 1.1});
		lhs -= rhs;
		CHECK(rhs.at(0) == Approx(2.3));
		CHECK(rhs.at(1) == Approx(4.6));
		CHECK(rhs.at(2) == Approx(1.1));
		CHECK(rhs.dimensions() == 3);
	}

	SECTION("Subtracting RHS with negative components from LHS with positive components") {
		auto lhs = comp6771::euclidean_vector({1.42, 1.2, 4.63});
		auto rhs = comp6771::euclidean_vector({-2.3, -4.6, -1.1});
		lhs -= rhs;
		CHECK(rhs.at(0) == Approx(-2.3));
		CHECK(rhs.at(1) == Approx(-4.6));
		CHECK(rhs.at(2) == Approx(-1.1));
		CHECK(rhs.dimensions() == 3);
	}

	SECTION("Subtracting RHS with positive components from LHS with negative components") {
		auto lhs = comp6771::euclidean_vector({-1.42, -1.2, -4.63});
		auto rhs = comp6771::euclidean_vector({2.3, 4.6, 1.1});
		lhs -= rhs;
		CHECK(rhs.at(0) == Approx(2.3));
		CHECK(rhs.at(1) == Approx(4.6));
		CHECK(rhs.at(2) == Approx(1.1));
		CHECK(rhs.dimensions() == 3);
	}

	SECTION("Subtracting RHS with negative components from LHS with negative components") {
		auto lhs = comp6771::euclidean_vector({-1.42, -1.2, -4.63});
		auto rhs = comp6771::euclidean_vector({-2.3, -4.6, -1.1});
		lhs -= rhs;
		CHECK(rhs.at(0) == Approx(-2.3));
		CHECK(rhs.at(1) == Approx(-4.6));
		CHECK(rhs.at(2) == Approx(-1.1));
		CHECK(rhs.dimensions() == 3);
	}
}

TEST_CASE("Compound subtraction should throw when LHS and RHS sizes are unequal") {
	SECTION("Subtracting empty RHS from 1D LHS") {
		auto lhs = comp6771::euclidean_vector({2.2});
		auto const rhs = comp6771::euclidean_vector({});
		CHECK_THROWS_AS(lhs -= rhs, comp6771::euclidean_vector_error);
	}

	SECTION("Subtracting 2D RHS from empty LHS") {
		auto lhs = comp6771::euclidean_vector({});
		auto const rhs = comp6771::euclidean_vector({5.3, -1.3});
		CHECK_THROWS_AS(lhs -= rhs, comp6771::euclidean_vector_error);
	}

	SECTION("Subtracting 2D RHS from 5D LHS") {
		auto lhs = comp6771::euclidean_vector({3.1, 4.2, -3.1, -7.4, 23.4});
		auto const rhs = comp6771::euclidean_vector({5.3, -1.3});
		CHECK_THROWS_AS(lhs -= rhs, comp6771::euclidean_vector_error);
	}

	SECTION("Subtracting 5D RHS from 1D LHS") {
		auto lhs = comp6771::euclidean_vector({3.1});
		auto const rhs = comp6771::euclidean_vector({5.3, -1.3, 3, 2.3, 1.03});
		CHECK_THROWS_AS(lhs -= rhs, comp6771::euclidean_vector_error);
	}
}