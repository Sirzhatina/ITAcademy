#pragma once

#include <vector>
#include <optional>
#include <memory>
#include "Tree.h"
#include "TreeKind.h"

namespace hw9 {
    /// @brief class collecting the trees into a single entity.
    /// The forests can be created from the given kinds of trees,
    /// have trees grown up inside, have them all cut, printed and merged.
    class Forest {
    public:
        /// @brief default constructor. Creates an empty forest without trees.
        Forest() = default;
        /// @brief constructor creating a forest with pre-created trees from passed kinds.
        /// Essentially, the constructor accepts only one type and is made generic only to
        /// take a variadic amount of objects of this type.
        /// @param t - Kind of trees of a variadic number to create trees from them which will be then a part of the new forest.
        template <class... TreeKinds>
            requires
        (std::same_as<TreeKinds, TreeKind> && ...)
            Forest(TreeKinds... t) {
            (m_trees.push_back(std::make_shared<Tree>(t)), ...);
        }

        /// @brief method to grow up in this forest a new tree of a passed kind.
        /// @param t - a kind of a tree to grow up.
        /// @return a pointer to the created tree.
        std::weak_ptr<Tree> growUp(TreeKind t);
        /// @brief method growing up a tree seeded randomly by another tree of this forest.
        /// If the forest is empty, a tree can't be grown up from the unexisted tree's seed,
        /// so, in this case, it effectively does nothing.
        /// @param a pointer to the created tree. If the forest is empty, 
        /// tree is not created and the pointer is nullptr.
        std::weak_ptr<Tree> growUp();
        /// @brief cuts all the trees of the forest making it effectively empty.
        void cutAll();
        /// @brief print to the standard output data about each tree in the forest.
        /// Effectively, calls wind() method of each tree.
        void wind() const;
        /// @brief operator to combine to forests and return a new one, with all trees inside.
        /// @param rhs - a forest to merge with.
        /// @return new forest containing all the trees from two operands.
        Forest operator+(const Forest& rhs) const;

    private:

        std::vector<std::shared_ptr<Tree>> m_trees;
    };
}