#pragma once

#include "AbstractTree.h"

class Maple : public AbstractTree {
public:
	Maple() : AbstractTree{ hw9::TreeKind::Maple } { }

	void wind() const override {
		std::cout << "Calling the wind() of Maple.\n";
		AbstractTree::wind();
	}
};