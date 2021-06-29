///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector constructors to ensure correct
// instantiation and correct constructor is used in different use-cases.
//
// TEST DESIGN RATIONALE
//
// The approach to testing design is property-based. The overall test design is done through
// abstraction of properties and conditions. A property is a particular characteristic of the output
// that is true e.g. a solution will always have same length words. A condition is a scenario/case
// where the property can be exhibited e.g. a solution will have the same length words for a single
// word ladder, or a solution will have the same length words for all word ladders.
//
// Hierarchy of the test design:
// 	- test file: collection of similar properties or a single property that we want to test
// 	- test case: a particular condition about the property that is true i.e. something should do
// something
// 	- test section: various words which will give an output to show the property to be true for a
// condition we are testing.
//
// I use this particular hierarchy because it neatly separates properties, conditions, and test
// sections. Using test sections also allows me to use "english_lexicon" as a test fixture which
// looks cleaner and requires less code (and is also recommended by authors of catch2)
//
// The TEST_CASE names are also descriptive to give an idea of what the test case is for and follows
// a "something should something" format. Therefore TEST_CASE is not commented as it will be
// redundant to rewrite what the test case is for. Comments will only be given at the top of the
// file to clarify why we are testing a particular property. The only time the "something should
// something" format is not followed is when exact word ladder solutions are given to be tested -
// this is for general confidence.
//
// Some test files will only have a single test case if the property to be tested is simple.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <sstream>

TEST_CASE("Basic constructor") {
	// Please note - this test may not function, it's just here for stubbing purposes
	auto const a1 = comp6771::euclidean_vector(3, 3.0);
	auto const a2 = comp6771::euclidean_vector(3, 3.0);
	auto const a3 = comp6771::euclidean_vector(3, 3.0);

	auto oss = std::ostringstream{};
	oss << (a1 + a2 + a3);
	CHECK(oss.str() == "[9 9 9]");
}

TEST_CASE("Basic constructor should instantiate correctly") {
	SECTION("Default values") {
		auto vec = comp6771::euclidean_vector();
		CHECK(vec.at(0) == 0.0);
		CHECK(vec.dimensions() == 1);
	}
}
TEST_CASE("Constructor taking a dimension should instantiate correctly") {
	SECTION("0 dimension") {
		auto vec = comp6771::euclidean_vector(0);
		CHECK(vec.dimensions() == 0);
	}

	SECTION("1 dimension") {
		auto vec = comp6771::euclidean_vector(1);
		CHECK(vec.at(0) == 0.0);
		CHECK(vec.dimensions() == 1);
	}

	SECTION("2 dimensions") {
		auto vec = comp6771::euclidean_vector(2);
		CHECK(vec.at(0) == 0.0);
		CHECK(vec.at(1) == 0.0);
		CHECK(vec.dimensions() == 2);
	}

	SECTION("Large dimension") {
		auto vec = comp6771::euclidean_vector(10);
		CHECK(vec.at(0) == 0.0);
		CHECK(vec.at(1) == 0.0);
		CHECK(vec.at(2) == 0.0);
		CHECK(vec.at(3) == 0.0);
		CHECK(vec.at(4) == 0.0);
		CHECK(vec.at(5) == 0.0);
		CHECK(vec.at(6) == 0.0);
		CHECK(vec.at(7) == 0.0);
		CHECK(vec.at(8) == 0.0);
		CHECK(vec.at(9) == 0.0);
		CHECK(vec.dimensions() == 10);
	}
}

TEST_CASE("Constructor taking a dimension and value should instantiate correctly") {
	SECTION("0 dimension and 0 value") {
		auto vec = comp6771::euclidean_vector(0, 0.0);
		CHECK(vec.dimensions() == 0);
	}

	SECTION("1 dimension and 0 value") {
		auto vec = comp6771::euclidean_vector(1, 0.0);
		CHECK(vec.at(0) == 0.0);
		CHECK(vec.dimensions() == 1);
	}

	SECTION("2 dimensions and 0 value") {
		auto vec = comp6771::euclidean_vector(2, 0.0);
		CHECK(vec.at(0) == 0.0);
		CHECK(vec.at(1) == 0.0);
		CHECK(vec.dimensions() == 2);
	}

	SECTION("2 dimensions and positive value") {
		auto vec = comp6771::euclidean_vector(2, 4.2);
		CHECK(vec.at(0) == 4.2);
		CHECK(vec.at(1) == 4.2);
		CHECK(vec.dimensions() == 2);
	}

	SECTION("2 dimensions and negative value") {
		auto vec = comp6771::euclidean_vector(2, -5.6);
		CHECK(vec.at(0) == -5.6);
		CHECK(vec.at(1) == -5.6);
		CHECK(vec.dimensions() == 2);
	}

	SECTION("Larger dimension and some value") {
		auto vec = comp6771::euclidean_vector(5, 48.523);
		CHECK(vec.at(0) == 48.523);
		CHECK(vec.at(1) == 48.523);
		CHECK(vec.at(2) == 48.523);
		CHECK(vec.at(3) == 48.523);
		CHECK(vec.at(4) == 48.523);
		CHECK(vec.dimensions() == 5);
	}
}

TEST_CASE("Constructor taking start and end iterators should instantiate correctly") {}

TEST_CASE("Constructor taking an initialiser list should instantiate correctly") {}

TEST_CASE("Copy constructor should instantiate correctly") {}

TEST_CASE("Move constructor should instantiate correctly") {}