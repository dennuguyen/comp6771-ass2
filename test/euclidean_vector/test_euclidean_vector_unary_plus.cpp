///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector unary plus operator.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Unary plus should return copy") {
	SECTION("Empty euclidean vector") {
		auto const euc_vec1 = comp6771::euclidean_vector({});
		auto const euc_vec2 = +euc_vec1;
		CHECK(euc_vec2.dimensions() == 0);
	}

	SECTION("Zero euclidean vector") {
		auto const euc_vec1 = comp6771::euclidean_vector(3, 0.0);
		auto const euc_vec2 = +euc_vec1;
		CHECK(euc_vec2.at(0) == Approx(0.0));
		CHECK(euc_vec2.at(1) == Approx(0.0));
		CHECK(euc_vec2.at(2) == Approx(0.0));
		CHECK(euc_vec2.dimensions() == 3);
	}

	SECTION("1 dimension euclidean vector") {
		auto const euc_vec1 = comp6771::euclidean_vector({1.0});
		auto const euc_vec2 = +euc_vec1;
		CHECK(euc_vec2.at(0) == Approx(1.0));
	}

	SECTION("2 dimension euclidean vector") {
		auto const euc_vec1 = comp6771::euclidean_vector({-42.0, 21.3});
		auto const euc_vec2 = +euc_vec1;
		CHECK(euc_vec2.at(0) == Approx(-42.0));
		CHECK(euc_vec2.at(1) == Approx(21.3));
	}

	SECTION("3 dimension euclidean vector") {
		auto const euc_vec1 = comp6771::euclidean_vector({-2.032, 8.3293, 12.429});
		auto const euc_vec2 = +euc_vec1;
		CHECK(euc_vec2.at(0) == Approx(-2.032));
		CHECK(euc_vec2.at(1) == Approx(8.3293));
		CHECK(euc_vec2.at(2) == Approx(12.429));
	}
}