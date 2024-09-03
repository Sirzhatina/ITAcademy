#include "AbstractForest.h"
#include "AbstractTree.h"
#include "utils.h"

namespace hw11 {
	void AbstractForest::wind() const {
		for (const auto t : m_trees) {
			t->wind();
		}
		itac::print("") << std::endl;
	}
}