#pragma once

#include "AbstractTree.h"
#include <iostream>

class Oak : public AbstractTree {
public:
	Oak() : AbstractTree{ hw9::TreeKind::Oak } { }

	void wind() const override {
		std::cout << "Calling the wind() of Oak.\n";
		AbstractTree::wind();
	}
};