#pragma once

#include "TreeKind.h"

namespace hw9 {
    /// @brief class describing a tree as a whole. It has its own unique ID and its kind.
    /// ID gets incremented for every constructed Tree and gets decremented for every destructed Tree.
    /// The tree can also report to the console its data. The class also counts the number of created trees.
    class Tree {
    public:
        static inline std::size_t treeCounter = 0;
    public:
        /// @brief Default constructor. If called, sets the tree to the unknown kind
        /// and invalid ID (0).
        Tree() = default;
        /// @brief constructs the object from the passed kind, assigns an ID to it 
        /// and increments the counter for each call.
        Tree(TreeKind kind);
        /// @brief destroys the object and decrements the counter.
        ~Tree();
        /// @brief getter to get a kind of the tree.
        /// @return Tree's kind.
        [[nodiscard]] TreeKind getKind() const;
        /// @brief getter to get the tree's ID.
        /// @return Tree's ID.
        [[nodiscard]] std::size_t getID() const;
        /// @brief method printing to the standard output the tree's kind and ID.
        void wind() const;

    private:

        TreeKind m_kind{ TreeKind::Unknown };

        std::size_t m_id{ 0 };
    };
}

