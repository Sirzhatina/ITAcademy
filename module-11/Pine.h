#pragma once

#include "AbstractTree.h"

class Pine : public AbstractTree {
public:
	Pine() : AbstractTree{ hw9::TreeKind::Pine } { }

	void wind() const override {
		std::cout << "Calling the wind() of Pine.\n";
		AbstractTree::wind();
	}
};