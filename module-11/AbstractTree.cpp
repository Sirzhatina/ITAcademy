#include "AbstractTree.h"
#include "utils.h"

AbstractTree::AbstractTree(hw9::TreeKind tk) : m_kind{ tk } { }

[[nodiscard]]
hw9::TreeKind AbstractTree::getKind() const { return m_kind; }

void AbstractTree::wind() const {
	itac::print("The tree kind: {}; ", hw9::asString(m_kind)) << std::endl;
}