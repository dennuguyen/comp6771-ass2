///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector vector norm utility function.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Norm of euclidean vector should square components element-wise and square root sum") {
	SECTION("Empty vector") {
		auto const euc_vec = comp6771::euclidean_vector({});
		auto const norm = comp6771::euclidean_norm(euc_vec);
		CHECK(norm == Approx(0.0));
	}

	SECTION("Zero vector") {
		auto const euc_vec = comp6771::euclidean_vector(5);
		auto const norm = comp6771::euclidean_norm(euc_vec);
		CHECK(norm == Approx(0.0));
	}

	SECTION("Euclidean vector with positive components") {
		auto const euc_vec = comp6771::euclidean_vector({4.8, 4.21, 543.2, 54.1});
		auto const norm = comp6771::euclidean_norm(euc_vec);
		CHECK(norm == Approx(545.9247));
	}

	SECTION("Euclidean vector with negative components") {
		auto const euc_vec = comp6771::euclidean_vector({-4.8, -4.21, -543.2, -54.1});
		auto const norm = comp6771::euclidean_norm(euc_vec);
		CHECK(norm == Approx(545.9247));
	}

	SECTION("Euclidean vector with positive and negative components") {
		auto const euc_vec = comp6771::euclidean_vector({4.8, -4.21, 543.2, -54.1});
		auto const norm = comp6771::euclidean_norm(euc_vec);
		CHECK(norm == Approx(545.9247));
	}
}

TEST_CASE("Norm should not modify input euclidean vector") {
	SECTION("Euclidean vector with some positive and negative components") {
		auto const euc_vec = comp6771::euclidean_vector({4.1, 3.2, -0.54, -5.9, 0.0});
		comp6771::euclidean_norm(euc_vec);
		CHECK(euc_vec.at(0) == Approx(4.1));
		CHECK(euc_vec.at(1) == Approx(3.2));
		CHECK(euc_vec.at(2) == Approx(-0.54));
		CHECK(euc_vec.at(3) == Approx(-5.9));
		CHECK(euc_vec.at(4) == Approx(0.0));
		CHECK(euc_vec.dimensions() == 5);
	}
}
