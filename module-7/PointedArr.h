#pragma once

#include <memory>

namespace hw7 {

	class PointedArr {
	public:
		PointedArr(std::size_t arrSize);

		[[nodiscard]] std::size_t getSize() const;

		[[nodiscard]] int& operator[](std::size_t index);
		
		[[nodiscard]] int operator[](std::size_t index) const;

	private:

		std::unique_ptr<int[]> m_pointer;

		std::size_t m_arraySize;
	};
}
