///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the copy and move assignment of a euclidean_vector to
// another euclidean_vector.
//
// TEST DESIGN RATIONALE
//
// The approach to testing design is property-based. The overall test design is done through
// abstraction of properties and conditions. A property is a particular characteristic of the output
// that is true. A condition is a scenario/case where the property can be exhibited.
//
// Hierarchy of the test design:
// 	- test file: collection of similar properties or a single property that we want to test
// 	- test case: a particular condition about the property that is true i.e. something should do
// something
// 	- test section: various cases which will give an output to show the property to be true for a
// condition we are testing.
//
// I use this particular hierarchy because it neatly separates properties, conditions, and
// use-cases.
//
// The TEST_CASE names are also descriptive to give an idea of what the test case is for and follows
// a "something should something" format. Therefore TEST_CASE is not commented as it will be
// redundant to rewrite what the test case is for. Comments will only be given at the top of the
// file to clarify why we are testing a particular property.
//
// Some test files will only have a single test case if the property to be tested is simple.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <vector>

TEST_CASE("Copy assignment should copy members correctly") {
	SECTION("Copy empty euclidean vector") {
		auto euc_vec1 = comp6771::euclidean_vector({});
		auto euc_vec2 = euc_vec1;
		CHECK(euc_vec1.dimensions() == 0);
		CHECK(euc_vec2.dimensions() == 0);
	}

	SECTION("Copy 1 dimension euclidean vector") {
		auto euc_vec1 = comp6771::euclidean_vector({3.4});
		auto euc_vec2 = euc_vec1;

		CHECK(euc_vec1.at(0) == Approx(3.4));
		CHECK(euc_vec1.dimensions() == 1);

		CHECK(euc_vec2.at(0) == Approx(3.4));
		CHECK(euc_vec2.dimensions() == 1);
	}

	SECTION("Copy multi-dimension euclidean vector") {
		auto euc_vec1 = comp6771::euclidean_vector({3.4, 6.1, 7.184181, 5.51});
		auto euc_vec2 = euc_vec1;

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

TEST_CASE("Writes to copy should not write to copied") {
	SECTION("Copy euclidean vector and write to it") {
		auto euc_vec1 = comp6771::euclidean_vector({3.4, 6.1, 7.184181, 5.51});
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
		auto euc_vec1 = comp6771::euclidean_vector({});
		auto euc_vec2 = std::move(euc_vec1);
		CHECK(euc_vec2.dimensions() == 0);
	}

	SECTION("Move 1 dimension euclidean vector") {
		auto euc_vec1 = comp6771::euclidean_vector({3.4});
		auto euc_vec2 = std::move(euc_vec1);
		CHECK(euc_vec2.at(0) == Approx(3.4));
		CHECK(euc_vec2.dimensions() == 1);
	}

	SECTION("Move multi-dimension euclidean vector") {
		auto euc_vec1 = comp6771::euclidean_vector({3.4, 6.1, 7.184181, 5.51});
		auto euc_vec2 = std::move(euc_vec1);
		CHECK(euc_vec2.at(0) == Approx(3.4));
		CHECK(euc_vec2.at(1) == Approx(6.1));
		CHECK(euc_vec2.at(2) == Approx(7.184181));
		CHECK(euc_vec2.at(3) == Approx(5.51));
		CHECK(euc_vec2.dimensions() == 4);
	}
}