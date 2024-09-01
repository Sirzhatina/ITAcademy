#include "Deciduous.h"
#include "AbstractTree.h"

namespace hw11 {
	bool Deciduous::isDeciduous(const AbstractTree& at) {
		return typeid(at) == typeid(Oak) || typeid(at) == typeid(Maple);
	}
}