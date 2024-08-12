#pragma once

#include <memory>
#include <iostream>
#include <optional>
#include <numeric>
#include <algorithm>
#include "StreamChecker.h"
#include "utils.h"

namespace hw7 {

    template <template <class> class SmartPtr, class T = int>
    static constexpr auto isUnique = std::is_same_v<SmartPtr<T[]>, std::unique_ptr<T[]>>;

    template <template <class> class SmartPtr, class T = int>
    static constexpr auto isWeak = std::is_same_v<SmartPtr<T[]>, std::weak_ptr<T[]>>;

    template <template <class> class SmartPtr, class T = int>
    static constexpr bool isShared = std::is_same_v<SmartPtr<T[]>, std::shared_ptr<T[]>>;

	template <template <class> class SmartPtr, class T = int>
    requires
        isUnique<SmartPtr, T> ||
        isShared<SmartPtr, T> ||
        isWeak<SmartPtr, T>
	class PointedArr {
	public:

        PointedArr(std::shared_ptr<T[]> sh, std::size_t arrSize) requires isShared<SmartPtr, T> || isWeak<SmartPtr, T>
            : m_pointer{ sh }
            , m_arraySize{ arrSize} { }
        
		PointedArr(std::size_t arrSize) requires isUnique<SmartPtr, T> || isShared<SmartPtr, T>
			: m_pointer{ new T[arrSize] }
			, m_arraySize{ arrSize } { }

		[[nodiscard]]
		std::size_t getSize() const { return m_arraySize; }

		[[nodiscard]]
		int& operator[](std::size_t index) {
            if constexpr (isWeak<SmartPtr, T>) {
                return m_pointer.lock()[index];
            }
            else {
                return m_pointer[index];
            }
        }

		[[nodiscard]]
		const int& operator[](std::size_t index) const {
            if constexpr (isWeak<SmartPtr, T>) {
                return m_pointer.lock()[index];
            }
            else {
                return m_pointer[index];
            }
        }

        std::optional<T> sum() const {
            auto sptr = getSharedOrUnique();
            
            if (sptr != nullptr && m_arraySize != 0) {
                return { std::accumulate(sptr.get(), sptr.get() + m_arraySize, 0) };
            }

            return {};
        }

        std::optional<std::pair<int, int>> minmax() const {

            if (auto p = getSharedOrUnique(); p != nullptr && getSize() != 0) {
                auto res = std::minmax_element(p.get(), p.get() + getSize());
                return { std::pair{ *res.first, *res.second } };
            }
            return {};
        }

    private:
        const std::unique_ptr<T[]>& getSharedOrUnique() const requires isUnique<SmartPtr<T[]>> {
            return m_pointer;
        }
        auto getSharedOrUnique() const {
            std::shared_ptr<T[]> ptr = nullptr;

            if constexpr (isWeak<SmartPtr, T>) {
                ptr = m_pointer.lock();
            }
            else {
                ptr = m_pointer;
            }

            return ptr;
        }
    private:

        SmartPtr<T[]> m_pointer;

        std::size_t m_arraySize;

	};

    template <template <class> class SPtr, class T = int>
    void inputElementsOf(hw7::PointedArr<SPtr, T>& pa) {
        itac::print("Enter {} numbers: ", pa.getSize());

        for (std::size_t i = 0; i < pa.getSize(); ++i) {
            std::cin >> pa[i];
        }

        StreamChecker strchk{};

        strchk.processStreamFailure(std::cout);
        strchk.processStreamFailure(std::cin);
    }

    template <template <class> class SPtr, class T = int>
    void printElementsOf(const hw7::PointedArr<SPtr, T>& pa) {
        itac::print("The numbers you've entered:");

        for (std::size_t i = 0; i < pa.getSize(); ++i) {
            itac::print(" {}", pa[i]);
        }
        std::cout << std::endl;

        StreamChecker strchk{};

        strchk.processStreamFailure(std::cout);
        strchk.processStreamFailure(std::cin);
    }

}
