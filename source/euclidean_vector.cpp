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

	euclidean_vector::euclidean_vector(euclidean_vector const& v)
	: magnitude_(std::unique_ptr<double[]>{v.magnitude_})
	, dimension_(v.dimension_) {}

	euclidean_vector::euclidean_vector(euclidean_vector&& v) noexcept
	: magnitude_(std::move(v.magnitude_))
	, dimension_(v.dimension_) {}

	auto euclidean_vector::operator=(euclidean_vector const& v) -> euclidean_vector& {
		*this = euclidean_vector(v);
		return *this;
	}

	auto euclidean_vector::operator=(euclidean_vector&& v) noexcept -> euclidean_vector& {
		*this = euclidean_vector(std::move(v));
		return *this;
	}

	auto euclidean_vector::operator[](euclidean_vector const& v) noexcept -> euclidean_vector& {}

	auto euclidean_vector::operator[](euclidean_vector& v) -> euclidean_vector& {}

	auto euclidean_vector::operator+() -> euclidean_vector {
		auto v = *this;
		return v;
	}

	auto euclidean_vector::operator-() noexcept -> euclidean_vector {
		auto v = *this;
		std::for_each (v.magnitude_.get(), v.magnitude_.get() + v.dimension_, [](auto& i) { i = -i; });
		return v;
	}

	auto euclidean_vector::operator+=(euclidean_vector const& v) -> euclidean_vector& {
		if (dimensions() != v.dimensions()) {
			auto const what = "Dimensions of LHS(" + std::to_string(dimensions()) + ") and RHS("
			                  + std::to_string(v.dimensions()) + ") do not match";
			throw euclidean_vector_error(what);
		}

		return *this;
	}

	auto euclidean_vector::operator-=(euclidean_vector const& v) -> euclidean_vector& {
		if (dimensions() != v.dimensions()) {
			auto const what = "Dimensions of LHS(" + std::to_string(dimensions()) + ") and RHS("
			                  + std::to_string(v.dimensions()) + ") do not match";
			throw euclidean_vector_error(what);
		}
		return *this;
	}

	auto euclidean_vector::operator*=(double) noexcept -> euclidean_vector& {
		return *this;
	}

	auto euclidean_vector::operator/=(double divisor) -> euclidean_vector& {
		if (divisor == 0.0) {
			throw euclidean_vector_error("Invalid vector division by 0");
		}
		return *this;
	}

	euclidean_vector::operator std::vector<double>() noexcept {}

	euclidean_vector::operator std::list<double>() noexcept {}

	[[nodiscard]] auto euclidean_vector::at(int component) const -> double {
		if (component < 0 || component >= dimensions_) {
			auto const what =
			   "Index " + std::to_string(component) + " is not valid for this euclidean_vector object";
			throw euclidean_vector_error(what);
		}
		return magnitude_.get(component);
	}

	auto euclidean_vector::at(int component) -> double& {
		if (component < 0 || component >= dimensions_) {
			auto const what =
			   "Index " + std::to_string(component) + " is not valid for this euclidean_vector object";
			throw euclidean_vector_error(what);
		}
	}

	[[nodiscard]] auto euclidean_vector::dimensions() const noexcept -> int {
		return static_cast<int>(dimension_);
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
		if (x.dimensions() != y.dimensions()) {
			auto const what = "Dimensions of LHS(" + std::to_string(x.dimensions()) + ") and RHS("
			                  + std::to_string(y.dimensions()) + ") do not match";
			throw euclidean_vector_error(what);
		}

		auto dot_product_value = 0.0;
		for (auto i = 0; i < x.dimensions(); i++) {
			dot_product_value += (x.at(i) * y.at(i));
		}
		return dot_product_value;
	}
} // namespace comp6771
