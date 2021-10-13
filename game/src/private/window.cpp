#include <GL/glew.h>
#include <cassert>
#include "window.h"

namespace game {
    void Window::initializeGL()
    {
        auto errorCode = glewInit();
        // TODO : Make this a proper logger later
        // Reference: https://youtu.be/yDgbNeYmG7g?t=605
        //
        assert(errorCode == 0);

        glGenBuffers(1, &this->vertexBufferId);
        glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferId);

        float vertices[] = {
            +0.0f, +0.1f,
            -0.1f, -0.1f,
            +0.1f, -0.1f,
        };

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    }

    void Window::paintGL()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
}
