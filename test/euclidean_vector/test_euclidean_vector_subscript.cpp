///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector subscripting operator.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Subscript should return the indexed value of the euclidean vector") {
	SECTION("7 dimensions") {
		auto const euc_vec = comp6771::euclidean_vector({1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1});
		CHECK(euc_vec[0] == Approx(1.1));
		CHECK(euc_vec[1] == Approx(2.1));
		CHECK(euc_vec[2] == Approx(3.1));
		CHECK(euc_vec[3] == Approx(4.1));
		CHECK(euc_vec[4] == Approx(5.1));
		CHECK(euc_vec[5] == Approx(6.1));
		CHECK(euc_vec[6] == Approx(7.1));
	}

	SECTION("16 dimensions") {
		auto const euc_vec = comp6771::euclidean_vector(
		   {8.5, -0.02, 92.1, 1.22321, 43.1, 9.9, 0, -2.3, -4.2, -12.429, 1.23, 49.2, -9.4, -0.23, 23.29, -94.493});
		CHECK(euc_vec[0] == Approx(8.5));
		CHECK(euc_vec[1] == Approx(-0.02));
		CHECK(euc_vec[2] == Approx(92.1));
		CHECK(euc_vec[3] == Approx(1.22321));
		CHECK(euc_vec[4] == Approx(43.1));
		CHECK(euc_vec[5] == Approx(9.9));
		CHECK(euc_vec[6] == Approx(0));
		CHECK(euc_vec[7] == Approx(-2.3));
		CHECK(euc_vec[8] == Approx(-4.2));
		CHECK(euc_vec[9] == Approx(-12.429));
		CHECK(euc_vec[10] == Approx(1.23));
		CHECK(euc_vec[11] == Approx(49.2));
		CHECK(euc_vec[12] == Approx(-9.4));
		CHECK(euc_vec[13] == Approx(-0.23));
		CHECK(euc_vec[14] == Approx(23.29));
		CHECK(euc_vec[15] == Approx(-94.493));
	}

	SECTION("100 dimensions") {
		auto const euc_vec = comp6771::euclidean_vector(100, 99.9);
		CHECK(euc_vec[0] == Approx(99.9));
		CHECK(euc_vec[3] == Approx(99.9));
		CHECK(euc_vec[8] == Approx(99.9));
		CHECK(euc_vec[10] == Approx(99.9));
		CHECK(euc_vec[43] == Approx(99.9));
		CHECK(euc_vec[58] == Approx(99.9));
		CHECK(euc_vec[89] == Approx(99.9));
		CHECK(euc_vec[99] == Approx(99.9));
	}
}

TEST_CASE("Subscript should return the reference of the indexed value of the euclidean vector") {
	SECTION("Modifying some indexed value") {
		auto euc_vec = comp6771::euclidean_vector(3, 1.1);
		euc_vec[2] = 132.2;
		CHECK(euc_vec[0] == Approx(1.1));
		CHECK(euc_vec[1] == Approx(1.1));
		CHECK(euc_vec[2] == Approx(132.2));
	}

	SECTION("Modifying some indexed value") {
		auto euc_vec = comp6771::euclidean_vector(100, 0.6);
		euc_vec[60] = -0.438;
		euc_vec[32] = 3290.2;
		CHECK(euc_vec[32] == Approx(3290.2));
		CHECK(euc_vec[60] == Approx(-0.438));
	}
}
