///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the copy and move assignment of a euclidean_vector to
// another euclidean_vector.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <vector>

TEST_CASE("Copy assignment should copy members correctly") {
	SECTION("Copy empty euclidean vector") {
		auto const euc_vec1 = comp6771::euclidean_vector({});
		auto const euc_vec2 = euc_vec1;
		CHECK(euc_vec1.dimensions() == 0);
		CHECK(euc_vec2.dimensions() == 0);
	}

	SECTION("Copy 1 dimension euclidean vector") {
		auto const euc_vec1 = comp6771::euclidean_vector({3.4});
		auto const euc_vec2 = euc_vec1;

		CHECK(euc_vec1.at(0) == Approx(3.4));
		CHECK(euc_vec1.dimensions() == 1);

		CHECK(euc_vec2.at(0) == Approx(3.4));
		CHECK(euc_vec2.dimensions() == 1);
	}

	SECTION("Copy multi-dimension euclidean vector") {
		auto const euc_vec1 = comp6771::euclidean_vector({3.4, 6.1, 7.184181, 5.51});
		auto const euc_vec2 = euc_vec1;

		CHECK(euc_vec1.at(0) == Approx(3.4));
		CHECK(euc_vec1.at(1) == Approx(6.1));
		CHECK(euc_vec1.at(2) == Approx(7.184181));
		CHECK(euc_vec1.at(3) == Approx(5.51));
		CHECK(euc_vec1.dimensions() == 4);

		CHECK(euc_vec2.at(0) == Approx(3.4));
		CHECK(euc_vec2.at(1) == Approx(6.1));
		CHECK(euc_vec2.at(2) == Approx(7.184181));
		CHECK(euc_vec2.at(3) == Approx(5.51));
		CHECK(euc_vec2.dimensions() == 4);
	}
}

TEST_CASE("Modifying the copy should not modify copied") {
	SECTION("Copy euclidean vector and write to it") {
		auto const euc_vec1 = comp6771::euclidean_vector({3.4, 6.1, 7.184181, 5.51});
		auto euc_vec2 = euc_vec1;
		euc_vec2.at(2) = 31.0;
		euc_vec2.at(3) = 51.312;

		CHECK(euc_vec1.at(0) == Approx(3.4));
		CHECK(euc_vec1.at(1) == Approx(6.1));
		CHECK(euc_vec1.at(2) == Approx(7.184181));
		CHECK(euc_vec1.at(3) == Approx(5.51));
		CHECK(euc_vec1.dimensions() == 4);

		CHECK(euc_vec2.at(0) == Approx(3.4));
		CHECK(euc_vec2.at(1) == Approx(6.1));
		CHECK(euc_vec2.at(2) == Approx(31.0));
		CHECK(euc_vec2.at(3) == Approx(51.312));
		CHECK(euc_vec2.dimensions() == 4);
	}
}

TEST_CASE("Move assignment should move members correctly") {
	SECTION("Move empty euclidean vector") {
		auto const euc_vec1 = comp6771::euclidean_vector({});
		auto const euc_vec2 = std::move(euc_vec1);
		CHECK(euc_vec2.dimensions() == 0);
	}

	SECTION("Move 1 dimension euclidean vector") {
		auto const euc_vec1 = comp6771::euclidean_vector({3.4});
		auto const euc_vec2 = std::move(euc_vec1);
		CHECK(euc_vec2.at(0) == Approx(3.4));
		CHECK(euc_vec2.dimensions() == 1);
	}

	SECTION("Move multi-dimension euclidean vector") {
		auto const euc_vec1 = comp6771::euclidean_vector({3.4, 6.1, 7.184181, 5.51});
		auto const euc_vec2 = std::move(euc_vec1);
		CHECK(euc_vec2.at(0) == Approx(3.4));
		CHECK(euc_vec2.at(1) == Approx(6.1));
		CHECK(euc_vec2.at(2) == Approx(7.184181));
		CHECK(euc_vec2.at(3) == Approx(5.51));
		CHECK(euc_vec2.dimensions() == 4);
	}
}