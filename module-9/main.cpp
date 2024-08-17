#include <vector>
#include <memory>
#include <iostream>
#include "Forest.h"
#include "Tree.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    using namespace hw9;

    Forest f{
        TreeKind::Oak,
        TreeKind::Oak,
        TreeKind::Pine
    };

    if (auto ok = f.growUp().lock()) {
        itac::print("The grown up tree:\t");
        ok->wind();
        itac::print("") << std::endl;
    }
    f.wind();
    itac::print("") << std::endl;

    Forest f2{
        TreeKind::Sequoia,
        TreeKind::Maple,
        TreeKind::Maple
    };
    f2.growUp(TreeKind::Sequoia);

    auto megaForest = f + f2;
    std::cout << "Mega forest be like:\n";
    megaForest.wind();

    megaForest.cutAll();
    std::cout << "Forest after cutting all:\n";
    megaForest.wind();

    return 0;
}