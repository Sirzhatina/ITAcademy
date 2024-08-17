#pragma once

#include "TreeKind.h"

namespace hw9 {
    class Tree {
    public:
        static inline std::size_t treeCounter = 0;
    public:
        Tree() = default;
        Tree(TreeKind kind);

        ~Tree();

        [[nodiscard]] TreeKind getKind() const;
        [[nodiscard]] std::size_t getID() const;

        void wind() const;

    private:

        TreeKind m_kind{ TreeKind::Unknown };

        std::size_t m_id{ 0 };
    };
}

