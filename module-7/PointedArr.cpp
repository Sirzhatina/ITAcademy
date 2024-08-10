#include "PointedArr.h"

using namespace hw7;

PointedArr::PointedArr(std::size_t arrSize)
	: m_pointer{ std::make_unique<int[]>(arrSize) }
	, m_arraySize{ arrSize } { }


[[nodiscard]]
std::size_t PointedArr::getSize() const { return m_arraySize; }

[[nodiscard]]
int& PointedArr::operator[](std::size_t index) { return m_pointer[index]; }

[[nodiscard]]
int PointedArr::operator[](std::size_t index) const { return m_pointer[index]; }