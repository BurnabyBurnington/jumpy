#include <X11/Xlib.h>
#include <X11/keysym.h>

#include "keyState.h"

namespace {
    Display* DISPLAY = XOpenDisplay(NULL);  // TODO: Check nullptr
}

namespace game {
    // TODO: Is there a way to now repeatedly query the display? Double-check this
    // Change this to be vector-based?
    // TODO: Might be template-able?
    //
    bool isKeyState(Direction const &direction)
    {
        char keyContent[32];
        XQueryKeymap(DISPLAY, keyContent);
        KeyCode code = XKeysymToKeycode(DISPLAY, static_cast<unsigned int>(direction));
        // TODO: Check if an explicit bool cast works
        // Reference: https://stackoverflow.com/a/49840783
        //
        return !!( keyContent[ code>>3 ] & ( 1<<( code & 7) ) );

        return false;
    }
}
