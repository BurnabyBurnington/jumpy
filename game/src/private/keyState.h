#pragma once

#include <X11/keysymdef.h>

enum class Direction {
    up=XK_Up,
    down=XK_Down,
    left=XK_Left,
    right=XK_Right,
};

namespace game {
    bool isKeyState(Direction const &direction);
}
