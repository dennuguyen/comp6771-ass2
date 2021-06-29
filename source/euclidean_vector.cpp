// Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#include "comp6771/euclidean_vector.hpp"
#include <cmath>
#include <memory>

namespace comp6771 {
	euclidean_vector::euclidean_vector() {}

	euclidean_vector::euclidean_vector(int dimension)
	: euclidean_vector(dimension, 0.0) {}

	euclidean_vector::euclidean_vector(int dimension, double value)
	: magnitude_(std::make_unique<double[]>(static_cast<std::size_t>(dimension)))
	, dimension_(static_cast<std::size_t>(dimension)) {}

	euclidean_vector::euclidean_vector(std::vector<double>::const_iterator start,
	                                   std::vector<double>::const_iterator end) {}

	euclidean_vector::euclidean_vector(std::initializer_list<double> list) {}

	euclidean_vector::euclidean_vector(euclidean_vector const& vec) {}

	euclidean_vector::euclidean_vector(euclidean_vector&& vec) noexcept
	: magnitude_(std::move(vec.magnitude_))
	, dimension_(vec.dimension_) {}

	auto euclidean_vector::operator=(euclidean_vector const& vec) -> euclidean_vector& {}
	auto euclidean_vector::operator=(euclidean_vector&& vec) noexcept -> euclidean_vector& {}
	auto euclidean_vector::operator[](euclidean_vector const& vec) noexcept -> euclidean_vector& {}
	auto euclidean_vector::operator[](euclidean_vector& vec) -> euclidean_vector& {}
	auto euclidean_vector::operator+() -> euclidean_vector {}
	auto euclidean_vector::operator-() -> euclidean_vector {}
	auto euclidean_vector::operator+=(euclidean_vector const&) -> euclidean_vector& {}
	auto euclidean_vector::operator-=(euclidean_vector const&) -> euclidean_vector& {}
	auto euclidean_vector::operator*=(double) -> euclidean_vector& {}
	auto euclidean_vector::operator/=(double) -> euclidean_vector& {}
	euclidean_vector::operator std::vector<double>() {}
	euclidean_vector::operator std::list<double>() {}

	[[nodiscard]] auto euclidean_vector::at(int component) const -> double {
		return this->magnitude_.get(component);
	}

	auto euclidean_vector::at(int component) -> double& {}

	[[nodiscard]] auto euclidean_vector::dimensions() const -> int {
		return static_cast<int>(this->dimension_);
	}

	auto euclidean_norm(euclidean_vector const& v) noexcept -> double {
		return std::sqrt(dot(v, v));
	}

	auto unit(euclidean_vector const& v) -> euclidean_vector {
		if (v.dimensions() == 0) {
			throw euclidean_vector_error("euclidean_vector with no dimensions does not have a unit "
			                             "vector");
		}

		auto unit_vector = euclidean_vector(v.dimensions(), 1.0);

		if (unit_vector == 0) {
			throw euclidean_vector_error("euclidean_vector with zero euclidean normal does not have a "
			                             "unit vector");
		}

		return unit_vector;
	}

	auto dot(euclidean_vector const& x, euclidean_vector const& y) -> double {
		if (x.dimensions() != y.dimensdimensions()) {
			throw euclidean_vector_error("Dimensions of LHS(X) and RHS(Y) do not match");
		}

		auto dot_product_value = 0.0;
		for (auto i = 0; i < x.dimensions(); i++) {
			dot_product_value += (x.at(i) * y.at(i));
		}
		return dot_product_value;
	}
} // namespace comp6771
