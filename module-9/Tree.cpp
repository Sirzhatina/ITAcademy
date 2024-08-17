#include "Tree.h"
#include "utils.h"

namespace hw9 {
    Tree::Tree(TreeKind kind) : m_kind{ kind } {
        if (m_kind != TreeKind::Unknown) {
            m_id = ++treeCounter;
        }
    }

    Tree::~Tree() {
        if (getKind() != TreeKind::Unknown) {
            --treeCounter;
        }
    }

    [[nodiscard]]
    TreeKind Tree::getKind() const { return m_kind; }
    [[nodiscard]]
    std::size_t Tree::getID() const { return m_id; }

    void Tree::wind() const {
        itac::print(
            "The name of the tree: {}; Its ID: {}.",
            asString(getKind()),
            getID()
        );
    }
}