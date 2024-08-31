#pragma once

#include "TreeKind.h"
#include "utils.h"

class AbstractTree {
public:
	AbstractTree() = default;
	virtual ~AbstractTree() = default;

	[[nodiscard]]
	hw9::TreeKind getKind() const;

	virtual void wind() const = 0;

protected:
	AbstractTree(hw9::TreeKind tk);
private:
	hw9::TreeKind m_kind{ hw9::TreeKind::Unknown };
};

#define DefTree(TreeName)									   \
class TreeName : public AbstractTree {						   \
	static inline std::size_t m_kindCounter = 0;			   \
public:														   \
	TreeName() : AbstractTree{ hw9::TreeKind::##TreeName } { } \
	~TreeName() { --m_kindCounter; }						   \
															   \
	void wind() const override {							   \
		itac::print("Calling the wind() of {}.\n", #TreeName); \
		AbstractTree::wind();								   \
	}														   \
															   \
private:													   \
		std::size_t m_##TreeName##Id{ ++m_kindCounter };	   \
};

DefTree(Pine)
DefTree(Oak)
DefTree(Maple)

#undef DefTree // undefined to prevent misproper usage