///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector list-type conversion operator.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iterator>
#include <sstream>

TEST_CASE("List type conversion should convert euclidean vector to list") {
	SECTION("Empty euclidean vector") {
		auto euc_vec = comp6771::euclidean_vector({});
		auto lst = static_cast<std::list<double>>(euc_vec);
		CHECK(lst.empty() == true);
	}

	SECTION("Zero euclidean vector") {
		auto euc_vec = comp6771::euclidean_vector({0.0, 0.0, 0.0, 0.0});
		auto lst = static_cast<std::list<double>>(euc_vec);
		CHECK(*std::next(lst.begin(), 0) == Approx(0.0));
		CHECK(*std::next(lst.begin(), 1) == Approx(0.0));
		CHECK(*std::next(lst.begin(), 2) == Approx(0.0));
		CHECK(*std::next(lst.begin(), 3) == Approx(0.0));
		CHECK(lst.size() == 4);
	}

	SECTION("1 dimension euclidean vector") {
		auto euc_vec = comp6771::euclidean_vector({1.0});
		auto lst = static_cast<std::list<double>>(euc_vec);
		CHECK(*std::next(lst.begin(), 0) == Approx(1.0));
		CHECK(lst.size() == 1);
	}

	SECTION("2 dimension euclidean vector") {
		auto euc_vec = comp6771::euclidean_vector({-42.0, 21.3});
		auto lst = static_cast<std::list<double>>(euc_vec);
		CHECK(*std::next(lst.begin(), 0) == Approx(-42.0));
		CHECK(*std::next(lst.begin(), 1) == Approx(21.3));
		CHECK(lst.size() == 2);
	}

	SECTION("3 dimension euclidean vector") {
		auto euc_vec = comp6771::euclidean_vector({-2.032, 8.3293, 12.429});
		auto lst = static_cast<std::list<double>>(euc_vec);
		CHECK(*std::next(lst.begin(), 0) == Approx(-2.032));
		CHECK(*std::next(lst.begin(), 1) == Approx(8.3293));
		CHECK(*std::next(lst.begin(), 2) == Approx(12.429));
	}
}