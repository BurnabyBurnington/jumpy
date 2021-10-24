#include <cassert>

#include <GL/glew.h>
#include <QDebug>
#include <QtCore/qnamespace.h>  // Needed for Qt::Key enums
#include <QtGui/QKeyEvent>

#include <clock.h>
#include <vector2D.h>
#include <keyState.h>
#include "window.h"

namespace {
    const float BASE_VELOCITY = 0.07f;
    engine::Vector2D VERTICES[] = {
        {-0.05f, +0.1f},
        {-0.1f, -0.1f},
        {+0.0f, -0.1f},
    };
    const unsigned int VERTICES_COUNT = sizeof(VERTICES) / sizeof(VERTICES[0]);
    engine::Vector2D SHIP_POSITION {0, 0};
    engine::Vector2D SHIP_VELOCITY {0, 0};
    engine::Clock CLOCK;
}

namespace game {
    void Window::initializeGL()
    {
        auto errorCode = glewInit();
        // TODO : Make this a proper logger later
        // Reference: https://youtu.be/yDgbNeYmG7g?t=605
        //
        assert(errorCode == 0);

        CLOCK.initialize();

        glGenBuffers(1, &this->vertexBufferId);
        glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferId);
        // glBufferData allocates and sends the data (points) to RAM
        // GL_DYNAMIC_DRAW - "Please refresh this buffer data over time"
        // NULL - "We will tell you where this RAM's points will be later"
        //
        glBufferData(GL_ARRAY_BUFFER, sizeof(VERTICES), NULL, GL_DYNAMIC_DRAW);

        this->connect(&this->timer, &QTimer::timeout, this, &Window::myUpdate);
        this->timer.start(0);
    }

    void Window::updateVelocity(float scalar)
    {
        auto acceleration = BASE_VELOCITY * scalar;
        // TODO: Is there a way to now repeatedly query the display? Double-check this
        // Change this to be vector-based?
        // TODO: Might be template-able?
        //
        if (game::isKeyState(game::Direction::up))
        {
            SHIP_VELOCITY.y += acceleration;
        }
        if (game::isKeyState(game::Direction::down))
        {
            SHIP_VELOCITY.y -= acceleration;
        }
        if (game::isKeyState(game::Direction::left))
        {
            SHIP_VELOCITY.x -= acceleration;
        }
        if (game::isKeyState(game::Direction::right))
        {
            SHIP_VELOCITY.x += acceleration;
        }

    }

    void Window::paintGL()
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glViewport(0, 0, this->width(), this->height());

        // To get OpenGL to send the data to RAM into the processing
        // pipeline, you have to tell OpenGL to enable that attribute
        // Attribute 0 is meaningless. But because we only have 1 attribute
        // (position), we use 0 as the 1st index in order to mean "position".
        //
        // TODO: Move this later
        //
        GLuint attributeIndex {0};
        glEnableVertexAttribArray(attributeIndex);
        // We now need to describe the attribute and data to OpenGL. We say
        // that the attribute is a float.
        //
        glVertexAttribPointer(attributeIndex, 2, GL_FLOAT, GL_FALSE, 0, 0);

        engine::Vector2D translatedVertices[VERTICES_COUNT];

        for (unsigned int index = 0; index < VERTICES_COUNT; ++index)
        {
            translatedVertices[index] = VERTICES[index] + SHIP_POSITION;
        }

        glBufferSubData(
            GL_ARRAY_BUFFER,
            0,
            sizeof(translatedVertices),
            translatedVertices
        );
        glDrawArrays(GL_TRIANGLES, 0, VERTICES_COUNT);
    }

    void Window::myUpdate()
    {
        // TODO: Need to make this a proper while loop, probably. And possibly
        // add ECS, if needed
        //
        CLOCK.newFrame();
        auto scalar = CLOCK.timeSinceLastFrame();
        this->updateVelocity(scalar);
        SHIP_POSITION += SHIP_VELOCITY;
        this->repaint();
    }
}
