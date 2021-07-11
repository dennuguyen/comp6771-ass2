///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector unit vector utility function.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Unit vector of euclidean vector and euclidean vector should have the same dimensions") {
	SECTION("1 dimension") {
		auto const euc_vec = comp6771::euclidean_vector(1, 10.4232);
		auto const unit = comp6771::unit(euc_vec);
		CHECK(unit.dimensions() == 1);
	}

	SECTION("2 dimension") {
		auto const euc_vec = comp6771::euclidean_vector(2, 10.4232);
		auto const unit = comp6771::unit(euc_vec);
		CHECK(unit.dimensions() == 2);
	}

	SECTION("49 dimension") {
		auto const euc_vec = comp6771::euclidean_vector(49, 10.4232);
		auto const unit = comp6771::unit(euc_vec);
		CHECK(unit.dimensions() == 49);
	}

	SECTION("210 dimension") {
		auto const euc_vec = comp6771::euclidean_vector(210, 10.4232);
		auto const unit = comp6771::unit(euc_vec);
		CHECK(unit.dimensions() == 210);
	}
}

TEST_CASE("Unit vector of euclidean vector should have components divided by norm element-wise") {
	SECTION("Euclidean vector with negative components") {
		auto const euc_vec = comp6771::euclidean_vector({-2.3, -5.3, -3.4});
		auto const unit = comp6771::unit(euc_vec);
		CHECK(unit.at(0) == Approx(-0.34309256122));
		CHECK(unit.at(1) == Approx(-0.79060459759));
		CHECK(unit.at(2) == Approx(-0.50718030789));
		CHECK(unit.dimensions() == 3);
	}

	SECTION("Euclidean vector with positive components") {
		auto const euc_vec = comp6771::euclidean_vector({4.8, 4.21, 543.2, 54.1});
		auto const unit = comp6771::unit(euc_vec);
		CHECK(unit.at(0) == Approx(0.008792421));
		CHECK(unit.at(1) == Approx(0.007711686));
		CHECK(unit.at(2) == Approx(0.995009019));
		CHECK(unit.at(3) == Approx(0.099097916));
		CHECK(unit.dimensions() == 4);
	}

	SECTION("Euclidean vector with positive and negative components") {
		auto const euc_vec = comp6771::euclidean_vector({1.232, -1.232, 43.343, -2342.1, 23.9, -0.932});
		auto const unit = comp6771::unit(euc_vec);
		CHECK(unit.at(0) == Approx(0.000525906043648));
		CHECK(unit.at(1) == Approx(-0.00052590604365));
		CHECK(unit.at(2) == Approx(0.018501903936547));
		CHECK(unit.at(3) == Approx(-0.99977641625608));
		CHECK(unit.at(4) == Approx(0.010202235749336));
		CHECK(unit.at(5) == Approx(-0.00039784450704));
		CHECK(unit.dimensions() == 6);
	}
}

TEST_CASE("Euclidean vector with no dimensions should throw") {
	SECTION("No dimensions") {
		auto const euc_vec = comp6771::euclidean_vector({});
		CHECK_THROWS_AS(comp6771::unit(euc_vec), comp6771::euclidean_vector_error);
	}
}

TEST_CASE("Euclidean vector with zero euclidean normal should throw") {
	SECTION("1 dimension zero euclidean vector") {
		auto const euc_vec = comp6771::euclidean_vector(1);
		CHECK_THROWS_AS(comp6771::unit(euc_vec), comp6771::euclidean_vector_error);
	}

	SECTION("2 dimension zero euclidean vector") {
		auto const euc_vec = comp6771::euclidean_vector(2);
		CHECK_THROWS_AS(comp6771::unit(euc_vec), comp6771::euclidean_vector_error);
	}

	SECTION("10 dimension zero euclidean vector") {
		auto const euc_vec = comp6771::euclidean_vector(10);
		CHECK_THROWS_AS(comp6771::unit(euc_vec), comp6771::euclidean_vector_error);
	}

	SECTION("100 dimension zero euclidean vector") {
		auto const euc_vec = comp6771::euclidean_vector(100);
		CHECK_THROWS_AS(comp6771::unit(euc_vec), comp6771::euclidean_vector_error);
	}
}
