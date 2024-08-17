#include "TreeKind.h"

namespace hw9 {
    std::string asString(TreeKind tk) {
        using enum TreeKind;

        switch (tk)
        {
        case Oak:
            return "oak";
        case Pine:
            return "pine";
        case Maple:
            return "maple";
        case Sequoia:
            return "sequoia";
        }
        return "unknown";
    }
}