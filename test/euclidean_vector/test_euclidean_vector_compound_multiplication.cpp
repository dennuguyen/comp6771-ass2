///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector compound multiplication operator.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <sstream>

TEST_CASE("Compound multiplication of zero euclidean vector should return zero euclidean vector") {
	SECTION("Multiplying zero euclidean vector with zero multiplier") {
		auto euc_vec = comp6771::euclidean_vector({0.0, 0.0});
		euc_vec *= 0.0;
		CHECK(euc_vec.at(0) == Approx(0.0));
		CHECK(euc_vec.at(1) == Approx(0.0));
		CHECK(euc_vec.dimensions() == 2);
	}

	SECTION("Multiplying zero euclidean vector with positive multiplier") {
		auto euc_vec = comp6771::euclidean_vector({0.0, 0.0});
		euc_vec *= 21.0;
		CHECK(euc_vec.at(0) == Approx(0.0));
		CHECK(euc_vec.at(1) == Approx(0.0));
		CHECK(euc_vec.dimensions() == 2);
	}

	SECTION("Multiplying zero euclidean vector with negative multiplier") {
		auto euc_vec = comp6771::euclidean_vector({0.0, 0.0});
		euc_vec *= -12.0;
		CHECK(euc_vec.at(0) == Approx(0.0));
		CHECK(euc_vec.at(1) == Approx(0.0));
		CHECK(euc_vec.dimensions() == 2);
	}
}

TEST_CASE("Compound multiplication with zero multiplier should return zero euclidean vector") {
	SECTION("Multiplying zero euclidean vector with zero multiplier") {
		auto euc_vec = comp6771::euclidean_vector({0.0, 0.0, 0.0});
		euc_vec *= 0.0;
		CHECK(euc_vec.at(0) == Approx(0.0));
		CHECK(euc_vec.at(1) == Approx(0.0));
		CHECK(euc_vec.at(2) == Approx(0.0));
		CHECK(euc_vec.dimensions() == 3);
	}

	SECTION("Multiplying euclidean vector with positive components with zero multiplier") {
		auto euc_vec = comp6771::euclidean_vector({6.1, 4.3, 5.2});
		euc_vec *= 0.0;
		CHECK(euc_vec.at(0) == Approx(0.0));
		CHECK(euc_vec.at(1) == Approx(0.0));
		CHECK(euc_vec.at(2) == Approx(0.0));
		CHECK(euc_vec.dimensions() == 3);
	}

	SECTION("Multiplying euclidean vector with negative components with zero multiplier") {
		auto euc_vec = comp6771::euclidean_vector({-6.1, -4.3, -5.2});
		euc_vec *= 0.0;
		CHECK(euc_vec.at(0) == Approx(0.0));
		CHECK(euc_vec.at(1) == Approx(0.0));
		CHECK(euc_vec.at(2) == Approx(0.0));
		CHECK(euc_vec.dimensions() == 3);
	}
}

TEST_CASE("Compound multiplication should multiply euclidean vector element-wise") {
	SECTION("Multiplying euclidean vector with positive components with positive multiplier") {
		auto euc_vec = comp6771::euclidean_vector({6.1, 21.2, 0.34});
		euc_vec *= 14.0;
		CHECK(euc_vec.at(0) == Approx(85.4));
		CHECK(euc_vec.at(1) == Approx(296.8));
		CHECK(euc_vec.at(2) == Approx(4.76));
		CHECK(euc_vec.dimensions() == 3);
	}

	SECTION("Multiplying euclidean vector with positive components with negative multiplier") {
		auto euc_vec = comp6771::euclidean_vector({6.1, 21.2, 0.34});
		euc_vec *= -14.0;
		CHECK(euc_vec.at(0) == Approx(-85.4));
		CHECK(euc_vec.at(1) == Approx(-296.8));
		CHECK(euc_vec.at(2) == Approx(-4.76));
		CHECK(euc_vec.dimensions() == 3);
	}

	SECTION("Multiplying euclidean vector with negative components with positive multiplier") {
		auto euc_vec = comp6771::euclidean_vector({-6.1, -21.2, -0.34});
		euc_vec *= 14.0;
		CHECK(euc_vec.at(0) == Approx(-85.4));
		CHECK(euc_vec.at(1) == Approx(-296.8));
		CHECK(euc_vec.at(2) == Approx(-4.76));
		CHECK(euc_vec.dimensions() == 3);
	}

	SECTION("Multiplying euclidean vector with negative components with negative multiplier") {
		auto euc_vec = comp6771::euclidean_vector({-6.1, -21.2, -0.34});
		euc_vec *= -14.0;
		CHECK(euc_vec.at(0) == Approx(85.4));
		CHECK(euc_vec.at(1) == Approx(296.8));
		CHECK(euc_vec.at(2) == Approx(4.76));
		CHECK(euc_vec.dimensions() == 3);
	}
}