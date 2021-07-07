///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector compound division operator.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <sstream>

TEST_CASE("Compound division by zero should throw") {
	SECTION("Dividing zero euclidean vector with zero divisor") {
		auto euc_vec = comp6771::euclidean_vector({0.0, 0.0});
		CHECK_THROWS_AS(euc_vec /= 0.0, comp6771::euclidean_vector_error);
	}

	SECTION("Dividing euclidean vector with positive components with zero divisor") {
		auto euc_vec = comp6771::euclidean_vector({30.0, 40.0});
		CHECK_THROWS_AS(euc_vec /= 0.0, comp6771::euclidean_vector_error);
	}

	SECTION("Dividing euclidean vector with negative components with zero divisor") {
		auto euc_vec = comp6771::euclidean_vector({-390.0, -50.0});
		CHECK_THROWS_AS(euc_vec /= 0.0, comp6771::euclidean_vector_error);
	}
}

TEST_CASE("Compound division of zero euclidean vector should have no effect") {
	SECTION("Dividing zero euclidean vector with positive divisor") {
		auto euc_vec = comp6771::euclidean_vector({0.0, 0.0});
		euc_vec /= 50.0;
		CHECK(euc_vec.at(0) == Approx(0.0));
		CHECK(euc_vec.at(1) == Approx(0.0));
		CHECK(euc_vec.dimensions() == 2);
	}

	SECTION("Dividing zero euclidean vector with negative divisor") {
		auto euc_vec = comp6771::euclidean_vector({0.0, 0.0});
		euc_vec /= -21.0;
		CHECK(euc_vec.at(0) == Approx(0.0));
		CHECK(euc_vec.at(1) == Approx(0.0));
		CHECK(euc_vec.dimensions() == 2);
	}
}

TEST_CASE("Compound division should divide euclidean vector element-wise") {
	SECTION("Dividing euclidean vector with positive components with positive divisor") {
		auto euc_vec = comp6771::euclidean_vector({6.1, 21.2, 0.34});
		euc_vec /= 14.0;
		CHECK(euc_vec.at(0) == Approx(0.435714));
		CHECK(euc_vec.at(1) == Approx(1.514287));
		CHECK(euc_vec.at(2) == Approx(0.024286));
		CHECK(euc_vec.dimensions() == 3);
	}

	SECTION("Dividing euclidean vector with positive components with negative divisor") {
		auto euc_vec = comp6771::euclidean_vector({6.1, 21.2, 0.34});
		euc_vec /= -14.0;
		CHECK(euc_vec.at(0) == Approx(-0.435714));
		CHECK(euc_vec.at(1) == Approx(-1.514287));
		CHECK(euc_vec.at(2) == Approx(-0.024286));
		CHECK(euc_vec.dimensions() == 3);
	}

	SECTION("Dividing euclidean vector with negative components with positive divisor") {
		auto euc_vec = comp6771::euclidean_vector({-3.213, -0.00433, -3129312.9539, -12.78});
		euc_vec /= 12.78;
		CHECK(euc_vec.at(0) == Approx(-0.2514084));
		CHECK(euc_vec.at(1) == Approx(-0.0003388106));
		CHECK(euc_vec.at(2) == Approx(-244860.17));
		CHECK(euc_vec.at(3) == Approx(-1.0));
		CHECK(euc_vec.dimensions() == 4);
	}

	SECTION("Dividing euclidean vector with negative components with negative divisor") {
		auto euc_vec = comp6771::euclidean_vector({-3.213, -0.00433, -3129312.9539, -12.78});
		euc_vec /= -12.78;
		CHECK(euc_vec.at(0) == Approx(0.2514084));
		CHECK(euc_vec.at(1) == Approx(0.0003388106));
		CHECK(euc_vec.at(2) == Approx(244860.17));
		CHECK(euc_vec.at(3) == Approx(1.0));
		CHECK(euc_vec.dimensions() == 4);
	}
}