#pragma once

// #include <X11/keysymdef.h>
// Reference: https://cgit.freedesktop.org/xorg/proto/x11proto/tree/keysymdef.h#n173
// TODO: Check if I can use a proper include, later
//
#define XK_Left                          0xff51  /* Move left, left arrow */
#define XK_Up                            0xff52  /* Move up, up arrow */
#define XK_Right                         0xff53  /* Move right, right arrow */
#define XK_Down                          0xff54  /* Move down, down arrow */

namespace game {
    enum class Direction {
        up=XK_Up,
        down=XK_Down,
        left=XK_Left,
        right=XK_Right,
    };

    bool isKeyState(Direction const &direction);
}
