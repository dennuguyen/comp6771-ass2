///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector vector-type conversion operator.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <vector>

TEST_CASE("Vector type conversion should convert euclidean vector to vector") {
	SECTION("Empty euclidean vector") {
		auto euc_vec = comp6771::euclidean_vector({});
		auto vec = static_cast<std::vector<double>>(euc_vec);
		CHECK(vec.empty() == true);
	}

	SECTION("Zero euclidean vector") {
		auto euc_vec = comp6771::euclidean_vector({0.0, 0.0, 0.0, 0.0});
		auto vec = static_cast<std::vector<double>>(euc_vec);
		CHECK(vec.at(0) == Approx(0.0));
		CHECK(vec.at(1) == Approx(0.0));
		CHECK(vec.at(2) == Approx(0.0));
		CHECK(vec.at(3) == Approx(0.0));
		CHECK(vec.size() == 4);
	}

	SECTION("1 dimension euclidean vector") {
		auto euc_vec = comp6771::euclidean_vector({1.0});
		auto vec = static_cast<std::vector<double>>(euc_vec);
		CHECK(vec.at(0) == Approx(1.0));
		CHECK(vec.size() == 1);
	}

	SECTION("2 dimension euclidean vector") {
		auto euc_vec = comp6771::euclidean_vector({-42.0, 21.3});
		auto vec = static_cast<std::vector<double>>(euc_vec);
		CHECK(vec.at(0) == Approx(-42.0));
		CHECK(vec.at(1) == Approx(21.3));
		CHECK(vec.size() == 2);
	}

	SECTION("3 dimension euclidean vector") {
		auto euc_vec = comp6771::euclidean_vector({-2.032, 8.3293, 12.429});
		auto vec = static_cast<std::vector<double>>(euc_vec);
		CHECK(vec.at(0) == Approx(-2.032));
		CHECK(vec.at(1) == Approx(8.3293));
		CHECK(vec.at(2) == Approx(12.429));
	}
}