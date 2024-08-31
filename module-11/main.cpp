#include "AbstractTree.h"
#include "Coniferous.h"
#include "Deciduous.h"

int main(int argc, char* argv[])
{
    std::unique_ptr<AbstractForest> conina = std::make_unique<Coniferous>();
    // should be ok
    bool coniSuccess = conina->growUp(
        std::make_shared<Pine>(),
        std::make_shared<Sequoia>()
    ); 

    if (!coniSuccess) {
        std::cout << "Can't add a deciduous tree to a coniferous forest!\n";
    }

    conina->wind();

    std::unique_ptr<AbstractForest> deSidius = std::make_unique<Deciduous>();
    
    // won't add a single tree
    bool addedDeciduous = deSidius->growUp(
        std::make_shared<Oak>(),
        std::make_shared<Maple>(),
        std::make_shared<Pine>()
    );

    if (!addedDeciduous) {
        std::cout << "Didn't add any tree of the passed ones, because one of them was conifer. Reconsider trees and try again!\n";
    }

    deSidius->growUp(std::make_shared<Oak>());
    // will show only one tree
    deSidius->wind();

    return 0;
}