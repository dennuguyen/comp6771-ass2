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
#include <utility>

namespace comp6771::util {
	auto is_double_equal(double const& a, double const& b) noexcept -> bool {
		return std::fabs(a - b) <= (std::fabs(a) < std::fabs(b) ? std::fabs(a) : std::fabs(b))
		                              * std::numeric_limits<double>::epsilon();
	}
} // namespace comp6771::util

namespace comp6771 {
	euclidean_vector::euclidean_vector() noexcept
	: euclidean_vector(1, 0.0) {}

	euclidean_vector::euclidean_vector(int size) noexcept
	: euclidean_vector(size, 0.0) {}

	euclidean_vector::euclidean_vector(int size, double value) noexcept
	: size_(static_cast<std::size_t>(size))
	, magnitude_(std::make_unique<double[]>(size_))
	, norm_(0.0)
	, valid_norm_(false) {
		std::fill(magnitude_.get(), magnitude_.get() + size_, value);
	}

	euclidean_vector::euclidean_vector(std::vector<double>::const_iterator first,
	                                   std::vector<double>::const_iterator last) noexcept
	: size_(static_cast<std::size_t>(std::distance(first, last)))
	, magnitude_(std::make_unique<double[]>(size_))
	, norm_(0.0)
	, valid_norm_(false) {
		std::copy(first, last, magnitude_.get());
	}

	euclidean_vector::euclidean_vector(std::initializer_list<double> lst) noexcept
	: size_(lst.size())
	, magnitude_(std::make_unique<double[]>(size_))
	, norm_(0.0)
	, valid_norm_(false) {
		std::copy(lst.begin(), lst.end(), magnitude_.get());
	}

	euclidean_vector::euclidean_vector(euclidean_vector const& euc_vec) noexcept
	: size_(euc_vec.size_)
	, magnitude_(std::make_unique<double[]>(size_))
	, norm_(euc_vec.norm_)
	, valid_norm_(euc_vec.valid_norm_) {
		std::copy(euc_vec.magnitude_.get(), euc_vec.magnitude_.get() + size_, magnitude_.get());
	}

	euclidean_vector::euclidean_vector(euclidean_vector&& euc_vec) noexcept
	: size_(std::exchange(euc_vec.size_, 0))
	, magnitude_(std::exchange(euc_vec.magnitude_, nullptr))
	, norm_(std::exchange(euc_vec.norm_, 0.0))
	, valid_norm_(std::exchange(euc_vec.valid_norm_, false)) {}

	auto euclidean_vector::operator=(euclidean_vector const& euc_vec) noexcept -> euclidean_vector& {
		return euclidean_vector(euc_vec).swap(*this);
	}

	auto euclidean_vector::operator=(euclidean_vector&& euc_vec) noexcept -> euclidean_vector& {
		size_ = std::exchange(euc_vec.size_, 0);
		magnitude_ = std::exchange(euc_vec.magnitude_, nullptr);
		norm_ = std::exchange(euc_vec.norm_, 0.0);
		valid_norm_ = std::exchange(euc_vec.valid_norm_, false);
		return *this;
	}

	auto euclidean_vector::operator[](int component) const noexcept -> double {
		assert(0 <= component && component < dimensions());
		return magnitude_[static_cast<std::size_t>(component)];
	}

	auto euclidean_vector::operator[](int component) noexcept -> double& {
		assert(0 <= component && component < dimensions());
		valid_norm_ = false;
		return magnitude_[static_cast<std::size_t>(component)];
	}

	auto euclidean_vector::operator+() const noexcept -> euclidean_vector {
		auto result = *this;
		return result;
	}

	auto euclidean_vector::operator-() const noexcept -> euclidean_vector {
		auto result = euclidean_vector(static_cast<int>(size_));
		std::transform(magnitude_.get(),
		               magnitude_.get() + size_,
		               result.magnitude_.get(),
		               std::negate<>());
		return result;
	}

	auto euclidean_vector::operator+=(euclidean_vector const& addend) -> euclidean_vector& {
		if (dimensions() != addend.dimensions()) {
			auto const what = "Dimensions of LHS(" + std::to_string(dimensions()) + ") and RHS("
			                  + std::to_string(addend.dimensions()) + ") do not match";
			throw euclidean_vector_error(what);
		}
		do_plus(*this, addend, *this);
		return *this;
	}

	auto euclidean_vector::operator-=(euclidean_vector const& subtrahend) -> euclidean_vector& {
		if (dimensions() != subtrahend.dimensions()) {
			auto const what = "Dimensions of LHS(" + std::to_string(dimensions()) + ") and RHS("
			                  + std::to_string(subtrahend.dimensions()) + ") do not match";
			throw euclidean_vector_error(what);
		}
		do_minus(*this, subtrahend, *this);
		return *this;
	}

	auto euclidean_vector::operator*=(double multiplier) noexcept -> euclidean_vector& {
		do_multiply(*this, multiplier, *this);
		return *this;
	}

	auto euclidean_vector::operator/=(double divisor) -> euclidean_vector& {
		if (util::is_double_equal(divisor, 0.0) == true) {
			throw euclidean_vector_error("Invalid vector division by 0");
		}
		do_divide(*this, divisor, *this);
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
		valid_norm_ = false;
		return magnitude_[static_cast<std::size_t>(component)];
	}

	[[nodiscard]] auto euclidean_vector::dimensions() const noexcept -> int {
		return static_cast<int>(size_);
	}

	auto euclidean_vector::swap(euclidean_vector& euc_vec) -> euclidean_vector& {
		std::swap(size_, euc_vec.size_);
		std::swap(magnitude_, euc_vec.magnitude_);
		std::swap(norm_, euc_vec.norm_);
		std::swap(valid_norm_, euc_vec.valid_norm_);
		return *this;
	}

	auto euclidean_vector::do_plus(euclidean_vector const& left_addend,
	                               euclidean_vector const& right_addend,
	                               euclidean_vector& sum) -> void {
		std::transform(left_addend.magnitude_.get(),
		               left_addend.magnitude_.get() + left_addend.size_,
		               right_addend.magnitude_.get(),
		               sum.magnitude_.get(),
		               [](auto const& lhs, auto const& rhs) { return std::plus<double>{}(lhs, rhs); });
		sum.valid_norm_ = false;
	}

	auto euclidean_vector::do_minus(euclidean_vector const& minuend,
	                                euclidean_vector const& subtrahend,
	                                euclidean_vector& difference) -> void {
		std::transform(minuend.magnitude_.get(),
		               minuend.magnitude_.get() + minuend.size_,
		               subtrahend.magnitude_.get(),
		               difference.magnitude_.get(),
		               [](auto const& lhs, auto const& rhs) { return std::minus<double>{}(lhs, rhs); });
		difference.valid_norm_ = false;
	}

	auto euclidean_vector::do_multiply(euclidean_vector const& multiplicand,
	                                   double multiplier,
	                                   euclidean_vector& product) noexcept -> void {
		std::transform(multiplicand.magnitude_.get(),
		               multiplicand.magnitude_.get() + multiplicand.size_,
		               product.magnitude_.get(),
		               [multiplier](auto const& component) {
			               return std::multiplies<double>{}(component, multiplier);
		               });
		product.valid_norm_ = false;
	}

	auto euclidean_vector::do_divide(euclidean_vector const& dividend,
	                                 double divisor,
	                                 euclidean_vector& quotient) -> void {
		std::transform(
		   dividend.magnitude_.get(),
		   dividend.magnitude_.get() + dividend.size_,
		   quotient.magnitude_.get(),
		   [divisor](auto& component) { return std::divides<double>{}(component, divisor); });
		quotient.valid_norm_ = false;
	}

	auto unit(euclidean_vector const& v) -> euclidean_vector {
		if (v.dimensions() == 0) {
			throw euclidean_vector_error("euclidean_vector with no dimensions does not have a unit "
			                             "vector");
		}
		auto norm = euclidean_norm(v);
		if (norm == 0) {
			throw euclidean_vector_error("euclidean_vector with zero euclidean normal does not have a "
			                             "unit vector");
		}
		return v / norm;
	}
} // namespace comp6771
