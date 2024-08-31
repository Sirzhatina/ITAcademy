#include "Deciduous.h"
#include "AbstractTree.h"

bool Deciduous::isDeciduous(const AbstractTree& at) {
	return typeid(at) == typeid(Oak) || typeid(at) == typeid(Maple);
}