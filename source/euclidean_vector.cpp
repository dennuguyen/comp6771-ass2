// Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#include "comp6771/euclidean_vector.hpp"

namespace comp6771 {
	euclidean_vector::euclidean_vector() {}
	euclidean_vector::euclidean_vector(int) {}
	euclidean_vector::euclidean_vector(int, double) {}
	euclidean_vector::euclidean_vector(std::vector<double>::const_iterator,
	                                   std::vector<double>::const_iterator) {}
	euclidean_vector::euclidean_vector(std::initializer_list<double>) {}
	euclidean_vector::euclidean_vector(euclidean_vector const&) {}
	euclidean_vector::euclidean_vector(euclidean_vector&&) noexcept {}
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
	auto euclidean_vector::dimensions() -> int {}
	auto operator==(euclidean_vector const&, euclidean_vector const&) -> bool {}
	auto operator!=(euclidean_vector const&, euclidean_vector const&) -> bool {}
	auto operator+(euclidean_vector const&, euclidean_vector const&) -> euclidean_vector {}
	auto operator-(euclidean_vector const&, euclidean_vector const&) -> euclidean_vector {}
	auto euclidean_vector::operator*(euclidean_vector const&, double) -> euclidean_vector {}
	auto euclidean_vector::operator/(euclidean_vector const&, double) -> euclidean_vector {}
	auto euclidean_vector::operator<<(std::ostream&, euclidean_vector const&) -> std::ostream& {}
	auto euclidean_vector::euclidean_norm(euclidean_vector const& v) -> double {}
	auto euclidean_vector::unit(euclidean_vector const& v) -> euclidean_vector {}
	auto euclidean_vector::dot(euclidean_vector const& x, euclidean_vector const& y) -> double {}
} // namespace comp6771
