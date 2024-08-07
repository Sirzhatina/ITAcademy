#include "SquareMatrix.h"
#include "utility/StreamChecker.h"
#include <iostream>

using namespace hw6;

SquareMatrix::SquareMatrix(std::size_t sz) : m_size{ sz } {
	m_matrix = new int* [m_size];
	for (int i = 0; i < m_size; ++i) {
		m_matrix[i] = new int[m_size];
	}
}

SquareMatrix::~SquareMatrix() {
	clear();
}

void SquareMatrix::clear() {
	if (m_matrix != nullptr) {
		for (int i = 0; i < m_size; ++i) {
			delete m_matrix[i];
		}
		delete m_matrix;
		m_matrix = nullptr;
	}
}

void SquareMatrix::generate() {
	if (m_matrix != nullptr) {
		for (int i = 0; i < m_size; ++i) {
			for (int j = 0; j < m_size; ++j) {
				m_matrix[i][j] = i * j;
			}
		}
	}
}

void SquareMatrix::printMatrix() {
	std::cout << "The matrix:\n";
	for (int i = 0; i < m_size; ++i) {
		for (int j = 0; j < m_size; ++j) {
			std::cout << m_matrix[i][j] << " ";
		}
		std::cout << '\n';
	}
	m_strchk.processStreamFailure(std::cout);
}