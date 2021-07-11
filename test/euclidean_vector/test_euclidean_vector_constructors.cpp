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

TEST_CASE("Basic constructor should instantiate correctly") {
	SECTION("Default values") {
		auto const euc_vec = comp6771::euclidean_vector();
		CHECK(euc_vec.at(0) == Approx(0.0));
		CHECK(euc_vec.dimensions() == 1);
	}
}
TEST_CASE("Constructor taking a dimension should instantiate correctly") {
	SECTION("0 dimension") {
		auto const euc_vec = comp6771::euclidean_vector(0);
		CHECK(euc_vec.dimensions() == 0);
	}

	SECTION("1 dimension") {
		auto const euc_vec = comp6771::euclidean_vector(1);
		CHECK(euc_vec.at(0) == Approx(0.0));
		CHECK(euc_vec.dimensions() == 1);
	}

	SECTION("2 dimensions") {
		auto const euc_vec = comp6771::euclidean_vector(2);
		CHECK(euc_vec.at(0) == Approx(0.0));
		CHECK(euc_vec.at(1) == Approx(0.0));
		CHECK(euc_vec.dimensions() == 2);
	}

	SECTION("Large dimension") {
		auto const euc_vec = comp6771::euclidean_vector(10);
		CHECK(euc_vec.at(0) == Approx(0.0));
		CHECK(euc_vec.at(1) == Approx(0.0));
		CHECK(euc_vec.at(2) == Approx(0.0));
		CHECK(euc_vec.at(3) == Approx(0.0));
		CHECK(euc_vec.at(4) == Approx(0.0));
		CHECK(euc_vec.at(5) == Approx(0.0));
		CHECK(euc_vec.at(6) == Approx(0.0));
		CHECK(euc_vec.at(7) == Approx(0.0));
		CHECK(euc_vec.at(8) == Approx(0.0));
		CHECK(euc_vec.at(9) == Approx(0.0));
		CHECK(euc_vec.dimensions() == 10);
	}
}

TEST_CASE("Constructor taking a dimension and value should instantiate correctly") {
	SECTION("0 dimension and 0 value") {
		auto const euc_vec = comp6771::euclidean_vector(0, 0.0);
		CHECK(euc_vec.dimensions() == 0);
	}

	SECTION("1 dimension and 0 value") {
		auto const euc_vec = comp6771::euclidean_vector(1, 0.0);
		CHECK(euc_vec.at(0) == Approx(0.0));
		CHECK(euc_vec.dimensions() == 1);
	}

	SECTION("2 dimensions and 0 value") {
		auto const euc_vec = comp6771::euclidean_vector(2, 0.0);
		CHECK(euc_vec.at(0) == Approx(0.0));
		CHECK(euc_vec.at(1) == Approx(0.0));
		CHECK(euc_vec.dimensions() == 2);
	}

	SECTION("2 dimensions and positive value") {
		auto const euc_vec = comp6771::euclidean_vector(2, 4.2);
		CHECK(euc_vec.at(0) == Approx(4.2));
		CHECK(euc_vec.at(1) == Approx(4.2));
		CHECK(euc_vec.dimensions() == 2);
	}

	SECTION("2 dimensions and negative value") {
		auto const euc_vec = comp6771::euclidean_vector(2, -5.6);
		CHECK(euc_vec.at(0) == Approx(-5.6));
		CHECK(euc_vec.at(1) == Approx(-5.6));
		CHECK(euc_vec.dimensions() == 2);
	}

	SECTION("Larger dimension and some value") {
		auto const euc_vec = comp6771::euclidean_vector(5, 48.523);
		CHECK(euc_vec.at(0) == Approx(48.523));
		CHECK(euc_vec.at(1) == Approx(48.523));
		CHECK(euc_vec.at(2) == Approx(48.523));
		CHECK(euc_vec.at(3) == Approx(48.523));
		CHECK(euc_vec.at(4) == Approx(48.523));
		CHECK(euc_vec.dimensions() == 5);
	}
}

TEST_CASE("Constructor taking start and end iterators should instantiate correctly") {
	SECTION("Zero vector") {
		auto const vec = std::vector<double>{};
		auto const euc_vec = comp6771::euclidean_vector(vec.begin(), vec.end());
		CHECK(euc_vec.dimensions() == 0);
	}

	SECTION("Full range of small vector") {
		auto const vec = std::vector<double>{513.0, 41.385, 1843.2348};
		auto const euc_vec = comp6771::euclidean_vector(vec.begin(), vec.end());
		CHECK(euc_vec.at(0) == Approx(513.0));
		CHECK(euc_vec.at(1) == Approx(41.385));
		CHECK(euc_vec.at(2) == Approx(1843.2348));
		CHECK(euc_vec.dimensions() == 3);
	}

	SECTION("Subset range including beginning and excluding end of vector") {
		auto const vec = std::vector<double>{3.0, 41.0, 824.13, 3.9, 0.1248, 24.182};
		auto const euc_vec = comp6771::euclidean_vector(vec.begin(), vec.begin() + 3);
		CHECK(euc_vec.at(0) == Approx(3.0));
		CHECK(euc_vec.at(1) == Approx(41.0));
		CHECK(euc_vec.at(2) == Approx(824.13));
		CHECK(euc_vec.dimensions() == 3);
	}

	SECTION("Subset range excluding beginning and including end of vector") {
		auto const vec = std::vector<double>{3.0, 41.0, 824.13, 3.9, 0.1248, 24.182};
		auto const euc_vec = comp6771::euclidean_vector(vec.begin() + 2, vec.end());
		CHECK(euc_vec.at(0) == Approx(824.13));
		CHECK(euc_vec.at(1) == Approx(3.9));
		CHECK(euc_vec.at(2) == Approx(0.1248));
		CHECK(euc_vec.at(3) == Approx(24.182));
		CHECK(euc_vec.dimensions() == 4);
	}

	SECTION("Subset range excluding beginning and excluding end of vector") {
		auto const vec = std::vector<double>{3.0, 41.0, 824.13, 3.9, 0.1248, 24.182};
		auto const euc_vec = comp6771::euclidean_vector(vec.begin() + 2, vec.begin() + 5);
		CHECK(euc_vec.at(0) == Approx(824.13));
		CHECK(euc_vec.at(1) == Approx(3.9));
		CHECK(euc_vec.at(2) == Approx(0.1248));
		CHECK(euc_vec.dimensions() == 3);
	}
}

TEST_CASE("Constructor taking an initialiser list should instantiate correctly") {
	SECTION("Empty initialiser list") {
		auto const euc_vec = comp6771::euclidean_vector({});
		CHECK(euc_vec.dimensions() == 0);
	}

	SECTION("1 dimension initialiser list") {
		auto const euc_vec = comp6771::euclidean_vector({1.1});
		CHECK(euc_vec.at(0) == Approx(1.1));
		CHECK(euc_vec.dimensions() == 1);
	}

	SECTION("Multi-dimension initialiser list") {
		auto const euc_vec = comp6771::euclidean_vector({1.1, 4.2, 6.9, 1.2394});
		CHECK(euc_vec.at(0) == Approx(1.1));
		CHECK(euc_vec.at(1) == Approx(4.2));
		CHECK(euc_vec.at(2) == Approx(6.9));
		CHECK(euc_vec.at(3) == Approx(1.2394));
		CHECK(euc_vec.dimensions() == 4);
	}
}

TEST_CASE("Copy constructor should instantiate correctly") {
	SECTION("Copy empty euclidean vector") {
		auto const euc_vec1 = comp6771::euclidean_vector({});
		auto const euc_vec2 = comp6771::euclidean_vector(euc_vec1);
		CHECK(euc_vec1.dimensions() == 0);
		CHECK(euc_vec2.dimensions() == 0);
	}

	SECTION("Copy 1 dimension euclidean vector") {
		auto const euc_vec1 = comp6771::euclidean_vector({3.4});
		auto const euc_vec2 = comp6771::euclidean_vector(euc_vec1);

		CHECK(euc_vec1.at(0) == Approx(3.4));
		CHECK(euc_vec1.dimensions() == 1);

		CHECK(euc_vec2.at(0) == Approx(3.4));
		CHECK(euc_vec2.dimensions() == 1);
	}

	SECTION("Copy multi-dimension euclidean vector") {
		auto const euc_vec1 = comp6771::euclidean_vector({3.4, 6.1, 7.184181, 5.51});
		auto const euc_vec2 = comp6771::euclidean_vector(euc_vec1);

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
		auto euc_vec2 = comp6771::euclidean_vector(euc_vec1);
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

TEST_CASE("Move constructor should instantiate correctly") {
	SECTION("Move empty euclidean vector") {
		auto euc_vec1 = comp6771::euclidean_vector({});
		auto const euc_vec2 = comp6771::euclidean_vector(std::move(euc_vec1));
		CHECK(euc_vec2.dimensions() == 0);
	}

	SECTION("Move 1 dimension euclidean vector") {
		auto euc_vec1 = comp6771::euclidean_vector({3.4});
		auto const euc_vec2 = comp6771::euclidean_vector(std::move(euc_vec1));
		CHECK(euc_vec2.at(0) == Approx(3.4));
		CHECK(euc_vec2.dimensions() == 1);
	}

	SECTION("Move multi-dimension euclidean vector") {
		auto euc_vec1 = comp6771::euclidean_vector({3.4, 6.1, 7.184181, 5.51});
		auto const euc_vec2 = comp6771::euclidean_vector(std::move(euc_vec1));
		CHECK(euc_vec2.at(0) == Approx(3.4));
		CHECK(euc_vec2.at(1) == Approx(6.1));
		CHECK(euc_vec2.at(2) == Approx(7.184181));
		CHECK(euc_vec2.at(3) == Approx(5.51));
		CHECK(euc_vec2.dimensions() == 4);
	}
}