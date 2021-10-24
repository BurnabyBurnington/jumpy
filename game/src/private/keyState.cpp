#include <X11/Xlib.h>
#include <X11/keysym.h>

#include "keyState.h"

namespace {
    Display* DISPLAY = XOpenDisplay(NULL);  // TODO: Check nullptr
}

namespace game {
    bool isKeyState(Direction const &direction)
    {
        char keyContent[32];
        XQueryKeymap(DISPLAY, keyContent);
        KeyCode code = XKeysymToKeycode(DISPLAY, direction);
        // TODO: Check if an explicit bool cast works
        // Reference: https://stackoverflow.com/a/49840783
        //
        return !!( keyContent[ code>>3 ] & ( 1<<( code & 7) ) );

        return false;
    }
}
