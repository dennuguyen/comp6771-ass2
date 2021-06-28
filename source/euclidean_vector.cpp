// Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#include "comp6771/euclidean_vector.hpp"

namespace comp6771 {
	euclidean_vector::euclidean_vector() {}

	euclidean_vector::euclidean_vector(int dimension)
	: magnitude_(std::make_unique<double[]>(static_cast<std::size_t>(dimension)))
	, dimension_(static_cast<std::size_t>(dimension)) {}

	euclidean_vector::euclidean_vector(int dimension, double value)
	: magnitude_(std::make_unique<double[]>(static_cast<std::size_t>(dimension)))
	, dimension_(static_cast<std::size_t>(dimension)) {}

	euclidean_vector::euclidean_vector(std::vector<double>::const_iterator start,
	                                   std::vector<double>::const_iterator end) {}

	euclidean_vector::euclidean_vector(std::initializer_list<double> list) {}

	euclidean_vector::euclidean_vector(euclidean_vector const& vec) {}

	euclidean_vector::euclidean_vector(euclidean_vector&& vec) noexcept
	: magnitude_(std::move(vec.magnitude_))
	, dimension_(std::move(vec.dimension_)) {}

	auto euclidean_vector::operator=(euclidean_vector const&) -> euclidean_vector& {}
	auto euclidean_vector::operator=(euclidean_vector&&) noexcept -> euclidean_vector& {}
	auto euclidean_vector::operator[](euclidean_vector const&) noexcept -> euclidean_vector& {}
	auto euclidean_vector::operator[](euclidean_vector&) -> euclidean_vector& {}
	auto euclidean_vector::operator+() -> euclidean_vector {}
	auto euclidean_vector::operator-() -> euclidean_vector {}
	auto euclidean_vector::operator+=(euclidean_vector const&) -> euclidean_vector& {}
	auto euclidean_vector::operator-=(euclidean_vector const&) -> euclidean_vector& {}
	auto euclidean_vector::operator*=(double) -> euclidean_vector& {}
	auto euclidean_vector::operator/=(double) -> euclidean_vector& {}
	euclidean_vector::operator std::vector<double>() {}
	euclidean_vector::operator std::list<double>() {}
	[[nodiscard]] auto euclidean_vector::at(int) const -> double {}
	auto euclidean_vector::at(int) -> double& {}

	[[nodiscard]] auto euclidean_vector::dimensions() const -> int {
		return static_cast<int>(this->dimension_);
	}

	auto euclidean_vector::euclidean_norm(euclidean_vector const& v) -> double {}
	auto euclidean_vector::unit(euclidean_vector const& v) -> euclidean_vector {}
	auto euclidean_vector::dot(euclidean_vector const& x, euclidean_vector const& y) -> double {}
} // namespace comp6771
