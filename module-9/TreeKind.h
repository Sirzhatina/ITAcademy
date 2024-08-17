#pragma once

#include <string>

namespace hw9 {
    enum class TreeKind {
        Unknown = -1,
        Oak,
        Pine,
        Maple,
        Sequoia
    };

    std::string asString(TreeKind tk);
}