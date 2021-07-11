#ifndef COMP6771_EUCLIDEAN_VECTOR_HPP
#define COMP6771_EUCLIDEAN_VECTOR_HPP

#include <algorithm>
#include <experimental/iterator>
#include <iostream>
#include <iterator>
#include <list>
#include <memory>
#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>

namespace comp6771::util {

	// Returns true if given doubles are the same.
	auto is_double_equal(double const& a, double const& b) noexcept -> bool;

} // namespace comp6771::util
namespace comp6771 {
	class euclidean_vector_error : public std::runtime_error {
	public:
		explicit euclidean_vector_error(std::string const& what)
		: std::runtime_error(what) {}
	};

	class euclidean_vector {
	public:
		// A constructor that generates a euclidean vector with a dimension of 1 and magnitude of 0.0.
		explicit euclidean_vector() noexcept;

		// A constructor that takes the number of dimensions (as a int) but no magnitudes, sets the
		// magnitude in each dimension as 0.0. You can assume the integer input will always be
		// non-negative.
		explicit euclidean_vector(int) noexcept;

		// A constructor that takes the number of dimensions (as an int) and initialises the magnitude
		// in each dimension as the second argument (a double). You can assume the integer input will
		// always be non-negative.
		explicit euclidean_vector(int, double) noexcept;

		// A constructor (or constructors) that takes the start and end of an iterator to a
		// std:vector<double> and works out the required dimensions, and sets the magnitude in each
		// dimension according to the iterated values.
		explicit euclidean_vector(std::vector<double>::const_iterator,
		                          std::vector<double>::const_iterator) noexcept;

		// A constructor that takes an initialiser list of doubles to populate vector magnitudes. You
		// will have to do your own research to implement this one.
		euclidean_vector(std::initializer_list<double>) noexcept;

		// Copy constructor.
		euclidean_vector(euclidean_vector const&) noexcept;

		// Move constructor.
		euclidean_vector(euclidean_vector&&) noexcept;

		// Default destructor.
		~euclidean_vector() = default;

		// A copy assignment operator overload.
		auto operator=(euclidean_vector const&) noexcept -> euclidean_vector&;

		// A move assignment operator.
		auto operator=(euclidean_vector&&) noexcept -> euclidean_vector&;

		// Allows to get and set the value in a given dimension of the Euclidean vector. Hint: you may
		// need two overloadeds to achieve this requirement. Note: It's a requirement you use asserts
		// to ensure the index passed is valid.
		auto operator[](int component) const noexcept -> double;
		auto operator[](int component) noexcept -> double&;

		// Returns a copy of the current object.
		auto operator+() const noexcept -> euclidean_vector;

		// Returns a copy of the current object, where each scalar value has its sign negated.
		auto operator-() const noexcept -> euclidean_vector;

		// For adding vectors of the same dimension.
		auto operator+=(euclidean_vector const&) -> euclidean_vector&;

		// For subtracting vectors of the same dimension.
		auto operator-=(euclidean_vector const&) -> euclidean_vector&;

		// For scalar multiplication, e.g. [1 2] * 3 = [3 6].
		auto operator*=(double) noexcept -> euclidean_vector&;

		// For scalar division, e.g. [3 6] / 2 = [1.5 3].
		auto operator/=(double) -> euclidean_vector&;

		// Operators for type casting to a std::vector.
		explicit operator std::vector<double>() const noexcept;

		// Operators for type casting to a std::list.
		explicit operator std::list<double>() const noexcept;

		// Returns the value of the magnitude in the dimension given as the function parameter.
		[[nodiscard]] auto at(int) const -> double;

		// Returns the reference of the magnitude in the dimension given as the function parameter.
		auto at(int) -> double&;

		// Return the number of dimensions in a particular euclidean_vector.
		[[nodiscard]] auto dimensions() const noexcept -> int;

		// True if the two vectors are equal in the number of dimensions and the magnitude in each
		// dimension is equal.
		friend auto operator==(euclidean_vector const& lhs, euclidean_vector const& rhs) noexcept
		   -> bool {
			if (lhs.dimensions() != rhs.dimensions()) {
				return false;
			}
			return std::equal(lhs.magnitude_.get(),
			                  lhs.magnitude_.get() + lhs.size_,
			                  rhs.magnitude_.get(),
			                  util::is_double_equal);
		}

		// True if the two vectors are not equal in the number of dimensions or the magnitude in each
		// dimension is not equal.
		friend auto operator!=(euclidean_vector const& lhs, euclidean_vector const& rhs) noexcept
		   -> bool {
			return !operator==(lhs, rhs);
		}

		// For adding vectors of the same dimension.
		friend auto operator+(euclidean_vector const& left_addend,
		                      euclidean_vector const& right_addend) -> euclidean_vector {
			auto sum = euclidean_vector(left_addend.dimensions());
			do_plus(left_addend, right_addend, sum);
			return sum;
		}

		// For substracting vectors of the same dimension.
		friend auto operator-(euclidean_vector const& minuend, euclidean_vector const& subtrahend)
		   -> euclidean_vector {
			auto difference = euclidean_vector(minuend.dimensions());
			do_minus(minuend, subtrahend, difference);
			return difference;
		}

		// For scalar multiplication, e.g. [1 2] * 3 = 3 * [1 2] = [3 6]. Hint: you'll need two
		// operators, as the scalar can be either side of the vector.
		friend auto operator*(euclidean_vector const& multiplicand, double multiplier) noexcept
		   -> euclidean_vector {
			auto product = euclidean_vector(multiplicand.dimensions());
			do_multiply(multiplicand, multiplier, product);
			return product;
		}

		friend auto operator*(double multiplier, euclidean_vector const& multiplicand) noexcept
		   -> euclidean_vector {
			return multiplicand * multiplier;
		}

		// For scalar division, e.g. [3 6] / 2 = [1.5 3].
		friend auto operator/(euclidean_vector const& dividend, double divisor) -> euclidean_vector {
			auto quotient = euclidean_vector(dividend.dimensions());
			do_divide(dividend, divisor, quotient);
			return quotient;
		}

		// Prints out the magnitude in each dimension of the Euclidean vector (surrounded by [ and ]),
		// e.g. for a 3-dimensional vector: [1 2 3]. Note: When printing the magnitude, simple use the
		// double << operator.
		friend auto operator<<(std::ostream& output, euclidean_vector const& euc_vec) noexcept
		   -> std::ostream& {
			output << "[";
			auto const vec = static_cast<std::vector<double>>(euc_vec);
			std::copy(vec.begin(), vec.end(), std::experimental::make_ostream_joiner(output, " "));
			output << "]";
			return output;
		}

		// Returns the Euclidean norm of the vector as a double. The Euclidean norm is the square root
		// of the sum of the squares of the magnitudes in each dimension. E.g, for the vector [1 2 3]
		// the Euclidean norm is sqrt(1*1 + 2*2 + 3*3) = 3.74. If v.dimensions() == 0, the result is
		// 0.
		friend auto euclidean_norm(euclidean_vector const& v) noexcept -> double {
			v.norm_ = std::sqrt(dot(v, v));
			v.valid_norm_ = true;
			return v.norm_;
		}

		// Computes the dot product of x ⋅ y; returns a double. E.g., [1 2] ⋅ [3 4] = 1 * 3 + 2 * 4 =
		// 11
		friend auto dot(euclidean_vector const& x, euclidean_vector const& y) -> double {
			if (x.dimensions() != y.dimensions()) {
				auto const what = "Dimensions of LHS(" + std::to_string(x.dimensions()) + ") and RHS("
				                  + std::to_string(y.dimensions()) + ") do not match";
				throw euclidean_vector_error(what);
			}
			return std::inner_product(x.magnitude_.get(),
			                          x.magnitude_.get() + x.dimensions(),
			                          y.magnitude_.get(),
			                          0.0);
		}

	private:
		// Function to carry out swap-and-copy idiom.
		auto swap(euclidean_vector&) -> euclidean_vector&;

		// Helper function to do addition of euclidean vectors.
		static auto do_plus(euclidean_vector const&, euclidean_vector const&, euclidean_vector&)
		   -> void;

		// Helper function to do subtraction of euclidean vectors.
		static auto do_minus(euclidean_vector const&, euclidean_vector const&, euclidean_vector&)
		   -> void;

		// Helper function to do scalar multiplication of euclidean vector.
		static auto do_multiply(euclidean_vector const&, double, euclidean_vector&) noexcept -> void;

		// Helper function to do scalar division of euclidean vector.
		static auto do_divide(euclidean_vector const&, double, euclidean_vector&) -> void;

		std::size_t size_; // Dimension of vector.

		// ass2 spec requires we use double[]
		// NOLINTNEXTLINE(modernize-avoid-c-arrays)
		std::unique_ptr<double[]> magnitude_; // Magnitudes of each dimension.

		mutable double norm_; // Save value of norm after computation.
		mutable bool valid_norm_; // Flag to indicate saved norm is valid.
	};

	auto euclidean_norm(euclidean_vector const& v) noexcept -> double;

	// Returns a Euclidean vector that is the unit vector of v. The magnitude for each dimension in
	// the unit vector is the original vector's magnitude divided by the Euclidean norm.
	auto unit(euclidean_vector const& v) -> euclidean_vector;

	auto dot(euclidean_vector const& x, euclidean_vector const& y) -> double;
} // namespace comp6771

#endif // COMP6771_EUCLIDEAN_VECTOR_HPP
