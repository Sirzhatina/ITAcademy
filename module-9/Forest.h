#pragma once

#include <vector>
#include <optional>
#include <memory>
#include "Tree.h"
#include "TreeKind.h"

namespace hw9 {

    class Forest {
    public:
        Forest() = default;

        template <class... TreeKinds>
            requires
        (std::same_as<TreeKinds, TreeKind> && ...)
            Forest(TreeKinds... t) {
            (m_trees.push_back(std::make_shared<Tree>(t)), ...);
        }


        std::weak_ptr<Tree> growUp(TreeKind t);
        // growing up a tree seeded randomly by another tree of this forest.
        // If the forest is empty, a tree can't be grown up from the unexisted tree's seed,
        // so, in this case, it effectively does nothing.
        std::weak_ptr<Tree> growUp();

        void cutAll();

        void wind() const;

        Forest operator+(const Forest& rhs) const;

    private:

        std::vector<std::shared_ptr<Tree>> m_trees;
    };
}