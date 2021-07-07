// Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#include "comp6771/euclidean_vector.hpp"
#include <cassert>
#include <cmath>
#include <functional>
#include <iterator>
#include <memory>
#include <stdexcept>

namespace comp6771 {
	euclidean_vector::euclidean_vector() noexcept
	: euclidean_vector(1, 0.0) {}

	euclidean_vector::euclidean_vector(int size) noexcept
	: euclidean_vector(size, 0.0) {}

	euclidean_vector::euclidean_vector(int size, double value) noexcept
	: size_(static_cast<std::size_t>(size))
	, magnitude_(std::make_unique<double[]>(size_)) {
		std::fill(magnitude_.get(), magnitude_.get() + size_, value);
	}

	euclidean_vector::euclidean_vector(std::vector<double>::const_iterator first,
	                                   std::vector<double>::const_iterator last) noexcept
	: size_(static_cast<std::size_t>(std::distance(first, last)))
	, magnitude_(std::make_unique<double[]>(size_)) {
		std::copy(first, last, magnitude_.get());
	}

	euclidean_vector::euclidean_vector(std::initializer_list<double> lst) noexcept
	: size_(lst.size())
	, magnitude_(std::make_unique<double[]>(size_)) {
		std::copy(lst.begin(), lst.end(), magnitude_.get());
	}

	euclidean_vector::euclidean_vector(euclidean_vector const& euc_vec) noexcept
	: size_(euc_vec.size_)
	, magnitude_(std::make_unique<double[]>(size_)) {
		std::copy(euc_vec.magnitude_.get(), euc_vec.magnitude_.get() + size_, magnitude_.get());
	}

	euclidean_vector::euclidean_vector(euclidean_vector&& euc_vec) noexcept
	: size_(std::exchange(euc_vec.size_, 0))
	, magnitude_(std::exchange(euc_vec.magnitude_, nullptr)) {}

	auto euclidean_vector::operator=(euclidean_vector const& euc_vec) noexcept -> euclidean_vector& {
		// *this = euclidean_vector(euc_vec);
		(void)euc_vec;
		return *this;
	}

	auto euclidean_vector::operator=(euclidean_vector&& euc_vec) noexcept -> euclidean_vector& {
		// std::swap(*this, euc_vec);
		(void)euc_vec;
		return *this;
	}

	auto euclidean_vector::operator[](int component) const noexcept -> double {
		assert(0 <= component && component < dimensions());
		return magnitude_[static_cast<std::size_t>(component)];
	}

	auto euclidean_vector::operator[](int component) noexcept -> double& {
		assert(0 <= component && component < dimensions());
		return magnitude_[static_cast<std::size_t>(component)];
	}

	auto euclidean_vector::operator+() const noexcept -> euclidean_vector {
		auto euc_vec = *this;
		return euc_vec;
	}

	auto euclidean_vector::operator-() const noexcept -> euclidean_vector {
		auto euc_vec = euclidean_vector(static_cast<int>(size_));
		std::transform(magnitude_.get(),
		               magnitude_.get() + size_,
		               euc_vec.magnitude_.get(),
		               std::negate<>());
		return euc_vec;
	}

	auto euclidean_vector::operator+=(euclidean_vector const& addend) -> euclidean_vector& {
		if (dimensions() != addend.dimensions()) {
			auto const what = "Dimensions of LHS(" + std::to_string(dimensions()) + ") and RHS("
			                  + std::to_string(addend.dimensions()) + ") do not match";
			throw euclidean_vector_error(what);
		}
		std::transform(magnitude_.get(),
		               magnitude_.get() + size_,
		               addend.magnitude_.get(),
		               magnitude_.get(),
		               [](auto const& lhs, auto const& rhs) { return std::plus<double>{}(lhs, rhs); });
		return *this;
	}

	auto euclidean_vector::operator-=(euclidean_vector const& subtrahend) -> euclidean_vector& {
		if (dimensions() != subtrahend.dimensions()) {
			auto const what = "Dimensions of LHS(" + std::to_string(dimensions()) + ") and RHS("
			                  + std::to_string(subtrahend.dimensions()) + ") do not match";
			throw euclidean_vector_error(what);
		}
		std::transform(magnitude_.get(),
		               magnitude_.get() + size_,
		               subtrahend.magnitude_.get(),
		               magnitude_.get(),
		               [](auto const& lhs, auto const& rhs) { return std::minus<double>{}(lhs, rhs); });
		return *this;
	}

	auto euclidean_vector::operator*=(double multiplier) noexcept -> euclidean_vector& {
		std::transform(magnitude_.get(),
		               magnitude_.get() + size_,
		               magnitude_.get(),
		               [multiplier](auto const& component) {
			               return std::multiplies<double>{}(component, multiplier);
		               });
		return *this;
	}

	auto euclidean_vector::operator/=(double divisor) -> euclidean_vector& {
		if (is_double_equal(divisor, 0.0) == true) {
			throw euclidean_vector_error("Invalid vector division by 0");
		}
		std::transform(
		   magnitude_.get(),
		   magnitude_.get() + size_,
		   magnitude_.get(),
		   [divisor](auto& component) { return std::divides<double>{}(component, divisor); });
		return *this;
	}

	euclidean_vector::operator std::vector<double>() const noexcept {
		auto vec = std::vector<double>(size_);
		std::copy(magnitude_.get(), magnitude_.get() + size_, vec.begin());
		return vec;
	}

	euclidean_vector::operator std::list<double>() const noexcept {
		auto lst = std::list<double>(size_);
		std::copy(magnitude_.get(), magnitude_.get() + size_, lst.begin());
		return lst;
	}

	[[nodiscard]] auto euclidean_vector::at(int component) const -> double {
		if (component < 0 || component >= dimensions()) {
			auto const what =
			   "Index " + std::to_string(component) + " is not valid for this euclidean_vector object";
			throw euclidean_vector_error(what);
		}
		return magnitude_[static_cast<std::size_t>(component)];
	}

	auto euclidean_vector::at(int component) -> double& {
		if (component < 0 || component >= dimensions()) {
			auto const what =
			   "Index " + std::to_string(component) + " is not valid for this euclidean_vector object";
			throw euclidean_vector_error(what);
		}
		return magnitude_[static_cast<std::size_t>(component)];
	}

	[[nodiscard]] auto euclidean_vector::dimensions() const noexcept -> int {
		return static_cast<int>(size_);
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
		if (euclidean_norm(unit_vector) == 0) {
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
