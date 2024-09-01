#include "Coniferous.h"
#include "AbstractTree.h"


namespace hw11 {
	bool Coniferous::isConiferous(const AbstractTree& at) {
		return typeid(at) == typeid(Pine) || typeid(at) == typeid(Sequoia);
	}
}