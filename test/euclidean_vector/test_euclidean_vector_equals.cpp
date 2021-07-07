///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector equals and not equals friends.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>

TEST_CASE("2 euclidean vectors with same dimensions and components element-wise should be equal") {
	SECTION("Empty euclidean vectors") {
		auto lhs = comp6771::euclidean_vector(0);
		auto rhs = comp6771::euclidean_vector(0);
		CHECK(lhs == rhs);
	}

	SECTION("Zero euclidean vectors") {
		auto lhs = comp6771::euclidean_vector(100, 0.0);
		auto rhs = comp6771::euclidean_vector(100, 0.0);
		CHECK(lhs == rhs);
	}

	SECTION("Euclidean vectors with some values") {
		auto lhs = comp6771::euclidean_vector({6.2, -0.43, 432.1, -0.4382, 43.210, 432.56});
		auto rhs = comp6771::euclidean_vector({6.2, -0.43, 432.1, -0.4382, 43.210, 432.56});
		CHECK(lhs == rhs);
	}
}

TEST_CASE("2 euclidean vectors with different dimensions should not be equal") {
	SECTION("Dimension of LHS is less than RHS") {
		auto lhs = comp6771::euclidean_vector(4);
		auto rhs = comp6771::euclidean_vector(5);
		CHECK(lhs != rhs);
	}

	SECTION("Dimension of LHS is greater than RHS") {
		auto lhs = comp6771::euclidean_vector(6);
		auto rhs = comp6771::euclidean_vector(5);
		CHECK(lhs != rhs);
	}
}

TEST_CASE("2 euclidean vectors with different components element-wise should not be equal") {
	SECTION("Unequal component at index 0") {
		auto lhs = comp6771::euclidean_vector({5.3, 0.0, 2.3});
		auto rhs = comp6771::euclidean_vector({3.5, 0.0, 2.3});
		CHECK(lhs != rhs);
	}

	SECTION("Unequal component at index 3") {
		auto lhs = comp6771::euclidean_vector({6.2, -0.43, 432.1, 0.4382, 43.210, 432.56});
		auto rhs = comp6771::euclidean_vector({6.2, -0.43, 432.1, -0.4382, 43.210, 432.56});
		CHECK(lhs != rhs);
	}

	SECTION("All unequal components") {
		auto lhs = comp6771::euclidean_vector({1, 2, 3, 4, 5, 6});
		auto rhs = comp6771::euclidean_vector({2, 3, 4, 5, 6, 7});
		CHECK(lhs != rhs);
	}

	SECTION("Negated euclidean vector") {
		auto lhs = comp6771::euclidean_vector({1, 2, 3, 4, 5, 6});
		auto rhs = comp6771::euclidean_vector({-1, -2, -3, -4, -5, -6});
		CHECK(lhs != rhs);
	}
}