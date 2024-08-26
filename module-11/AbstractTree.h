#pragma once

#include "TreeKind.h"
#include "utils.h"

class AbstractTree {
	static inline std::size_t treeCounter = 0;
public:
	AbstractTree() : m_counter{++treeCounter} { }
	virtual ~AbstractTree() { --treeCounter; }

	[[nodiscard]]
	hw9::TreeKind getKind() const { return m_kind; }

	virtual void wind() const = 0;

protected:
	AbstractTree(hw9::TreeKind tk) : m_kind{ tk } { }
private:
	hw9::TreeKind m_kind{ hw9::TreeKind::Unknown };

	std::size_t m_counter{ 0 };
};

void AbstractTree::wind() const {
	itac::print("Tree kind: {}; Tree counter: {}", hw9::asString(m_kind), m_counter) << std::endl;
}