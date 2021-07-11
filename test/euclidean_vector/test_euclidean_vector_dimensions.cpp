///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector dimensions method.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Dimensions should return the number of components of the euclidean vector") {
	SECTION("0 dimension") {
		auto const euc_vec = comp6771::euclidean_vector(0);
		CHECK(euc_vec.dimensions() == 0);
	}

	SECTION("1 dimension") {
		auto const euc_vec = comp6771::euclidean_vector(1);
		CHECK(euc_vec.dimensions() == 1);
	}

	SECTION("2 dimensions") {
		auto const euc_vec = comp6771::euclidean_vector(2);
		CHECK(euc_vec.dimensions() == 2);
	}

	SECTION("3 dimensions") {
		auto const euc_vec = comp6771::euclidean_vector(3);
		CHECK(euc_vec.dimensions() == 3);
	}

	SECTION("100 dimensions") {
		auto const euc_vec = comp6771::euclidean_vector(100);
		CHECK(euc_vec.dimensions() == 100);
	}

	SECTION("2512 dimensions") {
		auto const euc_vec = comp6771::euclidean_vector(2512);
		CHECK(euc_vec.dimensions() == 2512);
	}

	SECTION("10403 dimensions") {
		auto const euc_vec = comp6771::euclidean_vector(10403);
		CHECK(euc_vec.dimensions() == 10403);
	}
}