#include <algorithm>  // std::min
#include <cassert>

#include <GL/glew.h>
#include <QDebug>
#include <QtCore/qnamespace.h>  // Needed for Qt::Key enums
#include <QtGui/QKeyEvent>

#include <clock.h>
#include <matrix2D.h>
#include <radian.h>
#include <vector2D.h>

#include "keyState.h"
#include "window.h"

namespace {
    auto const BASE_VELOCITY = 0.07f;
    const math::Vector2D VERTICES[] = {
        {-0.05f, +0.1f},
        {-0.1f, -0.1f},
        {+0.0f, -0.1f},
    };
    auto const ANGULAR_MOVEMENT = 0.1f;
    const unsigned int VERTICES_COUNT = sizeof(VERTICES) / sizeof(VERTICES[0]);
    math::Vector2D SHIP_POSITION {0, 0};
    math::Vector2D SHIP_VELOCITY {0, 0};
    float SHIP_ORIENTATION {0.0};
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

    void Window::rotateShip(float scalar)
    {
        if (game::isKeyState(game::Direction::right))
        {
            SHIP_ORIENTATION -= ANGULAR_MOVEMENT * scalar;
        }
        if (game::isKeyState(game::Direction::left))
        {
            SHIP_ORIENTATION += ANGULAR_MOVEMENT * scalar;
        }
    }

    void Window::updateVelocity(float scalar)
    {
        auto const acceleration = BASE_VELOCITY * scalar;

        if (game::isKeyState(game::Direction::up))
        {
            SHIP_VELOCITY.y += acceleration;
        }
        if (game::isKeyState(game::Direction::down))
        {
            SHIP_VELOCITY.y -= acceleration;
        }

    }

    void Window::paintGL()
    {
        glClear(GL_COLOR_BUFFER_BIT);

        auto minimum = std::min(this->width(), this->height());
        math::Vector2D viewport {
            (this->width() / 2.0f) - (minimum / 2.0f),
            (this->height() / 2.0f) - (minimum / 2.0f)
        };
        glViewport(viewport.x, viewport.y, minimum, minimum);

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

        math::Vector2D transformedVertices[VERTICES_COUNT];
        auto transform = math::Matrix2D::rotate(math::Radian{SHIP_ORIENTATION});

        for (unsigned int index = 0; index < VERTICES_COUNT; ++index)
        {
            transformedVertices[index] = transform * VERTICES[index];
        }

        glBufferSubData(
            GL_ARRAY_BUFFER,
            0,
            sizeof(transformedVertices),
            transformedVertices
        );
        glDrawArrays(GL_TRIANGLES, 0, VERTICES_COUNT);
    }

    void Window::myUpdate()
    {
        // TODO: Need to make this a proper while loop, probably. And possibly
        // add ECS, if needed
        //
        CLOCK.newFrame();
        auto const scalar = CLOCK.timeSinceLastFrame();

        this->rotateShip(scalar);
        this->updateVelocity(scalar);
        SHIP_POSITION += SHIP_VELOCITY;

        this->repaint();
    }
}
