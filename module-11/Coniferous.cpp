#include "Coniferous.h"
#include "AbstractTree.h"


bool Coniferous::isConiferous(const AbstractTree& at) {
	return typeid(at) == typeid(Pine) || typeid(at) == typeid(Sequoia);
}