#ifndef COMP6771_EUCLIDEAN_VECTOR_HPP
#define COMP6771_EUCLIDEAN_VECTOR_HPP

#include <list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace comp6771 {
	class euclidean_vector_error : public std::runtime_error {
	public:
		explicit euclidean_vector_error(std::string const& what)
		: std::runtime_error(what) {}
	};

	class euclidean_vector {
	public:
		// A constructor that generates a euclidean vector with a dimension of 1 and magnitude of 0.0.
		// You can assume the integer input will always be non-negative.
		euclidean_vector();

		// A constructor that takes the number of dimensions (as a int) but no magnitudes, sets the
		// magnitude in each dimension as 0.0. You can assume the integer input will always be
		// non-negative.
		explicit euclidean_vector(int);

		// A constructor that takes the number of dimensions (as an int) and initialises the magnitude
		// in each dimension as the second argument (a double). You can assume the integer input will
		// always be non-negative.
		euclidean_vector(int, double);

		// A constructor (or constructors) that takes the start and end of an iterator to a
		// std:vector<double> and works out the required dimensions, and sets the magnitude in each
		// dimension according to the iterated values.
		euclidean_vector(std::vector<double>::const_iterator, std::vector<double>::const_iterator);

		// A constructor that takes an initialiser list of doubles to populate vector magnitudes. You
		// will have to do your own research to implement this one.
		euclidean_vector(std::initializer_list<double>);

		// Copy constructor.
		euclidean_vector(euclidean_vector const&);

		// Move constructor.
		euclidean_vector(euclidean_vector&&) noexcept;

		// Default destructor.
		~euclidean_vector() = default;

		// A copy assignment operator overload.
		auto operator=(euclidean_vector const&) -> euclidean_vector&;

		// A move assignment operator.
		auto operator=(euclidean_vector&&) noexcept -> euclidean_vector&;

		// Allows to get and set the value in a given dimension of the Euclidean vector. Hint: you may
		// need two overloadeds to achieve this requirement. Note: It's a requirement you use asserts
		// to ensure the index passed is valid.
		auto operator[](euclidean_vector const&) noexcept -> euclidean_vector&;
		auto operator[](euclidean_vector&) -> euclidean_vector&;

		// Returns a copy of the current object.
		auto operator+() -> euclidean_vector;

		// Returns a copy of the current object, where each scalar value has its sign negated.
		auto operator-() -> euclidean_vector;

		// For adding vectors of the same dimension.
		auto operator+=(euclidean_vector const&) -> euclidean_vector&;

		// For subtracting vectors of the same dimension.
		auto operator-=(euclidean_vector const&) -> euclidean_vector&;

		// For scalar multiplication, e.g. [1 2] * 3 = [3 6].
		auto operator*=(double) -> euclidean_vector&;

		// For scalar division, e.g. [3 6] / 2 = [1.5 3].
		auto operator/=(double) -> euclidean_vector&;

		// Operators for type casting to a std::vector.
		explicit operator std::vector<double>();

		// Operators for type casting to a std::list.
		explicit operator std::list<double>();

		// Returns the value of the magnitude in the dimension given as the function parameter.
		[[nodiscard]] auto at(int) const -> double;

		// Returns the reference of the magnitude in the dimension given as the function parameter.
		auto at(int) -> double&;

		// Return the number of dimensions in a particular euclidean_vector.
		auto dimensions() -> int;

		// True if the two vectors are equal in the number of dimensions and the magnitude in each
		// dimension is equal.
		friend auto operator==(euclidean_vector const&, euclidean_vector const&) -> bool {}

		// True if the two vectors are not equal in the number of dimensions or the magnitude in each
		// dimension is not equal.
		friend auto operator!=(euclidean_vector const&, euclidean_vector const&) -> bool {}

		// For adding vectors of the same dimension.
		friend auto operator+(euclidean_vector const&, euclidean_vector const&) -> euclidean_vector {}

		// For substracting vectors of the same dimension.
		friend auto operator-(euclidean_vector const&, euclidean_vector const&) -> euclidean_vector {}

		// For scalar multiplication, e.g. [1 2] * 3 = 3 * [1 2] = [3 6]. Hint: you'll need two
		// operators, as the scalar can be either side of the vector.
		friend auto operator*(euclidean_vector const&, double) -> euclidean_vector {}

		// For scalar division, e.g. [3 6] / 2 = [1.5 3].
		friend auto operator/(euclidean_vector const&, double) -> euclidean_vector {}

		// Prints out the magnitude in each dimension of the Euclidean vector (surrounded by [ and ]),
		// e.g. for a 3-dimensional vector: [1 2 3]. Note: When printing the magnitude, simple use the
		// double << operator.
		friend auto operator<<(std::ostream&, euclidean_vector const&) -> std::ostream& {}

	private:
		// Returns the Euclidean norm of the vector as a double. The Euclidean norm is the square root
		// of the sum of the squares of the magnitudes in each dimension. E.g, for the vector [1 2 3]
		// the Euclidean norm is sqrt(1*1 + 2*2 + 3*3) = 3.74. If v.dimensions() == 0, the result is
		// 0.
		auto euclidean_norm(euclidean_vector const& v) -> double;

		// Returns a Euclidean vector that is the unit vector of v. The magnitude for each dimension
		// in the unit vector is the original vector's magnitude divided by the Euclidean norm.
		auto unit(euclidean_vector const& v) -> euclidean_vector;

		// Computes the dot product of x ⋅ y; returns a double. E.g., [1 2] ⋅ [3 4] = 1 * 3 + 2 * 4 =
		// 11
		auto dot(euclidean_vector const& x, euclidean_vector const& y) -> double;

		// ass2 spec requires we use double[]
		// NOLINTNEXTLINE(modernize-avoid-c-arrays)
		std::unique_ptr<double[]> magnitude_; // Magnitudes of each direction in space.
	};
} // namespace comp6771
#endif // COMP6771_EUCLIDEAN_VECTOR_HPP
