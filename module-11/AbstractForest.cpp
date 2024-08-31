#include "AbstractForest.h"
#include "AbstractTree.h"
#include "utils.h"

void AbstractForest::wind() const {
	for (const auto t : m_trees) {
		t->wind();
	}
	itac::print("") << std::endl;
}