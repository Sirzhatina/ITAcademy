#pragma once

#include <memory>
#include <iostream>
#include <optional>
#include <numeric>
#include <algorithm>
#include "StreamChecker.h"
#include "utils.h"

namespace hw7 {
    
    // Helper variables to write type checks shorter.

    template <template <class> class SmartPtr, class T = int>
    static constexpr auto isUnique = std::is_same_v<SmartPtr<T[]>, std::unique_ptr<T[]>>;

    template <template <class> class SmartPtr, class T = int>
    static constexpr auto isWeak = std::is_same_v<SmartPtr<T[]>, std::weak_ptr<T[]>>;

    template <template <class> class SmartPtr, class T = int>
    static constexpr bool isShared = std::is_same_v<SmartPtr<T[]>, std::shared_ptr<T[]>>;


    /// @brief generic wrapper around one of three standard smart pointers:
    /// unique_ptr, shared_ptr or weak_ptr - pointing to the array. The wrapper lets user to
    /// refer to the elements by index, get an array's size, its sum and its min and max elements.
	template <template <class> class SmartPtr, class T = int>
    requires
        isUnique<SmartPtr, T> ||
        isShared<SmartPtr, T> ||
        isWeak<SmartPtr, T>
	class PointedArr {
	public:
        /// @brief Constructs an object from the passed shared pointer with the given size. 
        /// This constructor is only enabled for shared_ptr or weak_ptr passed as a parameter type.
        /// @param sh - shared pointer from which the instance is constructed.
        /// @param arrSize - the size of an array pointed to by sh.
        PointedArr(std::shared_ptr<T[]> sh, std::size_t arrSize) requires isShared<SmartPtr, T> || isWeak<SmartPtr, T>
            : m_pointer{ sh }
            , m_arraySize{ arrSize} { }
        /// @brief Constructs an object allocating an array on the heap with the given size.
        /// The constructor is only enabled for unique_ptr or shared_ptr passed as a parameter type.
        /// @param arrSize - the size of the newly allocated array.
		PointedArr(std::size_t arrSize) requires isUnique<SmartPtr, T> || isShared<SmartPtr, T>
			: m_pointer{ new T[arrSize] }
			, m_arraySize{ arrSize } { }
        /// @brief method to get the size of an array pointed to by the smart pointer.
        /// @return The size of an array.
		[[nodiscard]]
		std::size_t getSize() const { return m_arraySize; }
        /// @brief Operator to refer to an array's element by index. 
        /// In case the internal pointer is weak, the shared_ptr is created from it. 
        /// No additional checks of pointer validity are made, 
        /// so it's user responsinility to call the operator properly.
        /// @param index - index to refer to an element.
        /// @return an element placed on the n-th position inside the array.
		[[nodiscard]]
		int& operator[](std::size_t index) {
            if constexpr (isWeak<SmartPtr, T>) {
                return m_pointer.lock()[index];
            }
            else {
                return m_pointer[index];
            }
        }
        /// @brief const version of the index operator to follow const-correctnes.
        /// @param index - index to refer to an element.
        /// @return an immutable element to the n-th position inside the array.
		[[nodiscard]]
		const int& operator[](std::size_t index) const {
            if constexpr (isWeak<SmartPtr, T>) {
                return m_pointer.lock()[index];
            }
            else {
                return m_pointer[index];
            }
        }
        /// @brief sums the element of the array and returns the optional sum of them.
        /// In case the pointer is null or the array size is 0, returns an empty object.
        /// In all other cases, returns the sum, even for uninitialized (garbage) elements.
        /// @return optional value of the accumulated array elements.
        std::optional<T> sum() const {
            auto sptr = getSharedOrUnique();
            
            if (sptr != nullptr && m_arraySize != 0) {
                return { std::accumulate(sptr.get(), sptr.get() + m_arraySize, 0) };
            }

            return {};
        }
        /// @brief finds the highest and lowest value inside the array and returns
        /// an optional pair of them. In case the pointer is null or the array size is 0,
        /// the empty object is returned. Otherwise, the method returns the presented value,
        /// even for an uninitialized array.
        /// @return optional pair of the lowest and the highest values in the given order.
        std::optional<std::pair<int, int>> minmax() const {

            if (auto p = getSharedOrUnique(); p != nullptr && getSize() != 0) {
                auto res = std::minmax_element(p.get(), p.get() + getSize());
                return { std::pair{ *res.first, *res.second } };
            }
            return {};
        }

    private:
        
        /// @brief Helper method to refer to the underlying pointer appropriately
        /// depending on its type in a unified and consistent manner. For weak pointer, returns shared_ptr created from it.
        /// For shared_ptr, returns the pointer made from the underlying one.
        /// @return std::shared_ptr, pointing to the underlying array.
        std::shared_ptr<T[]> getSharedOrUnique() const {
            std::shared_ptr<T[]> ptr = nullptr;

            if constexpr (isWeak<SmartPtr, T>) {
                ptr = m_pointer.lock();
            }
            else {
                ptr = m_pointer;
            }

            return ptr;
        }
        /// @brief version of the helper method constructed to be called only with unique_ptr
        /// as the underlying pointer. Since this pointer can't be copied, it returns const reference to the pointer.
        /// @return constant reference to the underlying unique pointer.
        const std::unique_ptr<T[]>& getSharedOrUnique() const requires isUnique<SmartPtr<T[]>> {
            return m_pointer;
        }
    private:

        SmartPtr<T[]> m_pointer;

        std::size_t m_arraySize;

	};

    /// @brief helper function to get input from the user to fill the passed PointedArr with values.
    /// Method simply outputs the invitation for input and reads the number of elements equal to the passed
    /// object size. The function does stream failure checks and if some failure occur, the program exits instantly.
    /// @param pa - reference to the PointedArr object to read to it.
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
    /// @brief helper function for an PointedArr output. It effectively prints the message to the console and then
    /// does the same with all the underlying elements of the passed object, separating them with the whitespace.
    /// The function does stream failure checks and if some failure occur, the program exits instantly.
    /// @param pa immutable reference to the PointedArr object holding the array for output.
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
