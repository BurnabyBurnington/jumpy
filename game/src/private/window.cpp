#include <GL/glew.h>
#include <QDebug>
#include <cassert>
#include <vector2D.h>
#include "window.h"

static engine::Vector2D VERTICES[] = {
    {+0.0f, +0.1f},
    {-0.1f, -0.1f},
    {+0.1f, -0.1f},
};

static const unsigned int VERTICES_COUNT = sizeof(VERTICES) / sizeof(VERTICES[0]);


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

        // GL_DYNAMIC_DRAW - "Please refresh this buffer data over time"
        // NULL - "We will tell you where this RAM's points will be later"
        //
        glBufferData(GL_ARRAY_BUFFER, sizeof(VERTICES), NULL, GL_DYNAMIC_DRAW);

        this->connect(&this->timer, &QTimer::timeout, this, &Window::myUpdate);
        this->timer.start(0);
    }

    void Window::paintGL()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // TODO: Don't I need `shipPosition` in initializeGL?
        engine::Vector2D shipPosition {100, 100};
        engine::Vector2D translatedVertices[VERTICES_COUNT];

        for (unsigned int index = 0; index < VERTICES_COUNT; ++index)
        {
            translatedVertices[index] = VERTICES[index] + shipPosition;
        }

        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(translatedVertices), translatedVertices);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    void Window::myUpdate()
    {
    }
}
