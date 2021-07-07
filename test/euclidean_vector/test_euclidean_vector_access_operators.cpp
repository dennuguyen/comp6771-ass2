///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the access operation of euclidean_vector through
// subscripting and 'at' method.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>

TEST_CASE("[] access should return correct value") {}

TEST_CASE("at() access should return correct value") {}

TEST_CASE("[] access should be writeable") {}

TEST_CASE("at() access should be writeable") {}

TEST_CASE("[] access with const euclidean vector should not be writeable") {
	SECTION("Empty euclidean vector") {
		auto euc_vec1 = comp6771::euclidean_vector({});
		auto euc_vec2 = +euc_vec1;
		CHECK(euc_vec2.dimensions() == 0);
	}

	SECTION("Zero euclidean vector") {
		auto euc_vec1 = comp6771::euclidean_vector(3, 0.0);
		auto euc_vec2 = +euc_vec1;
		CHECK(euc_vec2.at(0) == Approx(0.0));
		CHECK(euc_vec2.at(1) == Approx(0.0));
		CHECK(euc_vec2.at(2) == Approx(0.0));
		CHECK(euc_vec2.dimensions() == 3);
	}
}

TEST_CASE("at() access with const euclidean vector should not be writeable") {
	SECTION("Empty euclidean vector") {
		auto euc_vec1 = comp6771::euclidean_vector({});
		auto euc_vec2 = +euc_vec1;
		CHECK(euc_vec2.dimensions() == 0);
	}

	SECTION("Zero euclidean vector") {
		auto euc_vec1 = comp6771::euclidean_vector(3, 0.0);
		auto euc_vec2 = +euc_vec1;
		CHECK(euc_vec2.at(0) == Approx(0.0));
		CHECK(euc_vec2.at(1) == Approx(0.0));
		CHECK(euc_vec2.at(2) == Approx(0.0));
		CHECK(euc_vec2.dimensions() == 3);
	}
}