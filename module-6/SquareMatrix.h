#pragma once

#include <cstddef>
#include "utility/StreamChecker.h"


/// @brief class for simple manipulation of the square matrix sized with the passed to
/// the constructor value. Matrix can be filled, printed and cleared. Also, when this matrix
/// is out of scope, it gets cleared automatically.
class SquareMatrix {
public:
	/// @brief constructor to pass the size of the underlying square matrix.
	/// @param sz - square matrix size.
	explicit SquareMatrix(std::size_t sz);
	/// @brief automatically deletes the underlying matrix before the object goes out of scope.
	~SquareMatrix();
	/// @brief deletes dynamically-allocated matrix.
	void clear();
	/// @brief assigns to each value of the matrix as a product of its indexes (row and column).
	void generate();
	/// @brief prints the matrix to the standard output as a square table of rows and columns.
	/// If the stream object sets in a fail state, the program stops immediately.
	void printMatrix();

private:

	std::size_t m_size{ 0 };
	int** m_matrix{ nullptr };

	StreamChecker m_strchk{};
};