#pragma once

#include <memory>
#include <vector>
#include <type_traits>

class AbstractTree;

namespace hw11 {
	/// @brief class representing the forest that can collect trees, get new trees grown up
	/// inside it and show info about every single tree in the forest.
	class AbstractForest {
	public:
		AbstractForest() = default;
		virtual ~AbstractForest() = default;

		/// @brief Method with variadic number of arguments to add every passed tree to the forest
		/// @tparam ...Tree - A set of parameters of type AbstractTree strictly
		/// @param ...at - Variadic pointer to trees to add to the forest
		/// @return - true if all trees have grown up successfully, false otherwise
		template <std::derived_from<AbstractTree>... Tree>
		bool growUp(std::shared_ptr<Tree>... at) {
			return (growUpImpl(at) && ...);
		}
		/// @brief Prints info about all trees of the forest to the console.
		void wind() const;

	protected:
		/// @brief make the passed tree a part of the forest.
		/// @param at - abstract tree pointer holding actual tree.
		/// @return treu if tree have been added to the forest, false otherwise.
		virtual bool growUpImpl(std::shared_ptr<AbstractTree> at) = 0;

		/// @brief const getter for internal tree array.
		/// @return const reference to the tree array.
		const auto& trees() const { return m_trees; }
		/// @brief non-const getter for internal tree array.
		/// @return non-const reference to the tree array.
		auto& trees() { return m_trees; }

	private:

		std::vector<std::shared_ptr<AbstractTree>> m_trees;
	};


/// @brief The macro that creates repetitive structure of a class derived from the AbstractForest.
/// It implements the AbstractForest abstract method and declares only two methods in general, 
/// one of which is static and must be implemented manually by the user.
/// @param ForestType - the name of the future forest class.
#define DefForest(ForestType)										\
class ForestType : public AbstractForest {							\
protected:															\
	bool growUpImpl(std::shared_ptr<AbstractTree> at) override {	\
		if (is##ForestType(*at)) {									\
			trees().push_back(at);									\
			return true;											\
		}															\
		return false;												\
	}																\
private:															\
	static bool is##ForestType(const AbstractTree& at);				\
};

DefForest(Coniferous)
DefForest(Deciduous)

#undef DefForest // undefined to prevent misproper usage
} // namespace hw11
