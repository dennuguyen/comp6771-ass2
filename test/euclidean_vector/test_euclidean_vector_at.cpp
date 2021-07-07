///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector at method.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <limits>

TEST_CASE("At should return the indexed value of the euclidean vector") {
	SECTION("7 dimensions") {
		auto const euc_vec = comp6771::euclidean_vector({1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1});
		CHECK(euc_vec.at(0) == 1.1);
		CHECK(euc_vec.at(1) == 2.1);
		CHECK(euc_vec.at(2) == 3.1);
		CHECK(euc_vec.at(3) == 4.1);
		CHECK(euc_vec.at(4) == 5.1);
		CHECK(euc_vec.at(5) == 6.1);
		CHECK(euc_vec.at(6) == 7.1);
	}

	SECTION("16 dimensions") {
		auto const euc_vec = comp6771::euclidean_vector(
		   {8.5, -0.02, 92.1, 1.22321, 43.1, 9.9, 0, -2.3, -4.2, -12.429, 1.23, 49.2, -9.4, -0.23, 23.29, -94.493});
		CHECK(euc_vec.at(0) == 8.5);
		CHECK(euc_vec.at(1) == -0.02);
		CHECK(euc_vec.at(2) == 92.1);
		CHECK(euc_vec.at(3) == 1.22321);
		CHECK(euc_vec.at(4) == 43.1);
		CHECK(euc_vec.at(5) == 9.9);
		CHECK(euc_vec.at(6) == 0);
		CHECK(euc_vec.at(7) == -2.3);
		CHECK(euc_vec.at(8) == -4.2);
		CHECK(euc_vec.at(9) == -12.429);
		CHECK(euc_vec.at(10) == 1.23);
		CHECK(euc_vec.at(11) == 49.2);
		CHECK(euc_vec.at(12) == -9.4);
		CHECK(euc_vec.at(13) == -0.23);
		CHECK(euc_vec.at(14) == 23.29);
		CHECK(euc_vec.at(15) == -94.493);
	}

	SECTION("100 dimensions") {
		auto const euc_vec = comp6771::euclidean_vector(100, 99.9);
		CHECK(euc_vec.at(0) == 99.9);
		CHECK(euc_vec.at(3) == 99.9);
		CHECK(euc_vec.at(8) == 99.9);
		CHECK(euc_vec.at(10) == 99.9);
		CHECK(euc_vec.at(43) == 99.9);
		CHECK(euc_vec.at(58) == 99.9);
		CHECK(euc_vec.at(89) == 99.9);
		CHECK(euc_vec.at(99) == 99.9);
	}
}

TEST_CASE("At should return the reference of the indexed value of the euclidean vector") {
	SECTION("Modifying some indexed value") {
		auto euc_vec = comp6771::euclidean_vector(3, 1.1);
		euc_vec.at(2) = 132.2;
		CHECK(euc_vec.at(0) == 1.1);
		CHECK(euc_vec.at(1) == 1.1);
		CHECK(euc_vec.at(2) == 132.2);
	}

	SECTION("Modifying some indexed value") {
		auto euc_vec = comp6771::euclidean_vector(100, 0.6);
		euc_vec.at(60) = -0.438;
		euc_vec.at(32) = 3290.2;
		CHECK(euc_vec.at(32) == 3290.2);
		CHECK(euc_vec.at(60) == -0.438);
	}
}

TEST_CASE("Out-of-bounds use of at should throw") {
	SECTION("Access empty euclidean vector") {
		auto const euc_vec = comp6771::euclidean_vector({});
		CHECK_THROWS_AS(euc_vec.at(0), comp6771::euclidean_vector_error);
	}
	SECTION("Access index less than zero") {
		auto const euc_vec = comp6771::euclidean_vector(3, 4.0);
		CHECK_THROWS_AS(euc_vec.at(-1), comp6771::euclidean_vector_error);
		CHECK_THROWS_AS(euc_vec.at(-2), comp6771::euclidean_vector_error);
		CHECK_THROWS_AS(euc_vec.at(-3), comp6771::euclidean_vector_error);
		CHECK_THROWS_AS(euc_vec.at(-100), comp6771::euclidean_vector_error);
		CHECK_THROWS_AS(euc_vec.at(-std::numeric_limits<int>::max()), comp6771::euclidean_vector_error);
	}

	SECTION("Access index greater than bound") {
		auto const euc_vec = comp6771::euclidean_vector(1543);
		CHECK_THROWS_AS(euc_vec.at(1543), comp6771::euclidean_vector_error);
		CHECK_THROWS_AS(euc_vec.at(1544), comp6771::euclidean_vector_error);
		CHECK_THROWS_AS(euc_vec.at(1545), comp6771::euclidean_vector_error);
		CHECK_THROWS_AS(euc_vec.at(1678), comp6771::euclidean_vector_error);
		CHECK_THROWS_AS(euc_vec.at(10432), comp6771::euclidean_vector_error);
		CHECK_THROWS_AS(euc_vec.at(200023), comp6771::euclidean_vector_error);
		CHECK_THROWS_AS(euc_vec.at(std::numeric_limits<int>::max()), comp6771::euclidean_vector_error);
	}
}