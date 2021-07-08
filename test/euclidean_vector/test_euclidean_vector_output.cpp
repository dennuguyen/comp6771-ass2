///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are related to the euclidean_vector output stream friend function. The
// example output from the spec is given as "[1 2 3]", from this format we do not display any
// trailing zeroes. There is no example for very large numbers, it will be assumed a shortened
// format is used therefore scientific notation is used.
//
// Refer to test_euclidean_vector_constructors.cpp for TEST DESIGN RATIONALE.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <sstream>

TEST_CASE("Output stream should return correct stream") {
	SECTION("Empty euclidean vector") {
		auto const euc_vec = comp6771::euclidean_vector({});
		auto os = std::ostringstream{};
		os << euc_vec;
		CHECK(os.str() == "[]");
	}

	SECTION("Zero euclidean vector") {
		auto const euc_vec = comp6771::euclidean_vector({0, 0.0, 0.00, 0.000, 0.0000, 0.00000});
		auto os = std::ostringstream{};
		os << euc_vec;
		CHECK(os.str() == "[0 0 0 0 0 0]");
	}

	SECTION("Simple euclidean vector") {
		auto const euc_vec = comp6771::euclidean_vector({5.42, 6.491, -9.32, -0.2, 13, 33.33});
		auto os = std::ostringstream{};
		os << euc_vec;
		CHECK(os.str() == "[5.42 6.491 -9.32 -0.2 13 33.33]");
	}

	// Scientific notation is used when positional numeration is greater than 6.
	SECTION("Large numbers euclidean vector") {
		auto const euc_vec = comp6771::euclidean_vector(
		   {233428943102.0, 23182328.0, 56489342.0, -48353.0, -534892.0, -2342723412.0});
		auto os = std::ostringstream{};
		os << euc_vec;
		CHECK(os.str() == "[2.33429e+11 2.31823e+07 5.64893e+07 -48353 -534892 -2.34272e+09]");
	}

	SECTION("Precise fractions euclidean vector") {
		auto const euc_vec = comp6771::euclidean_vector({0.23984324928423,
		                                                 0.3242384723847,
		                                                 -3294823420.34242340,
		                                                 0.00000000000000000000,
		                                                 0.2342343212300000,
		                                                 -230.00000000023218});
		auto os = std::ostringstream{};
		os << euc_vec;
		CHECK(os.str() == "[0.239843 0.324238 -3.29482e+09 0 0.234234 -230]");
	}
}