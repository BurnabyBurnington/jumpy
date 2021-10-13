#include <GL/glew.h>
#include <cassert>
#include "window.h"

namespace game {
    void Window::initializeGL()
    {
        auto error_code = glewInit();
        // TODO : Make this a proper logger later
        // Reference: https://youtu.be/yDgbNeYmG7g?t=605
        //
        assert(error_code == 0);
    }
}
