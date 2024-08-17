#pragma once

#include <string>

namespace hw9 {
    /// @brief Enum describing a kind of tree to the user.
    /// Kind of tree can be unknown.
    enum class TreeKind {
        Unknown = -1,
        Oak,
        Pine,
        Maple,
        Sequoia
    };
    /// @brief free function converting the passed kind of tree
    /// to the string equivalent.
    /// @param tk - A kind of tree to convert.
    /// @return Kind of tree's string equivalent.
    std::string asString(TreeKind tk);
}