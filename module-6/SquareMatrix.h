#pragma once

#include <cstddef>
#include "utility/StreamChecker.h"

class SquareMatrix {
public:
	SquareMatrix(std::size_t sz);

	~SquareMatrix();

	void clear();

	void generate();
	void printMatrix();

private:

	std::size_t m_size{ 0 };
	int** m_matrix{ nullptr };

	StreamChecker m_strchk{};
};