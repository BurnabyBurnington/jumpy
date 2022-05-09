#include <cmath>  // std::cos, std::sin
#include <algorithm>  // std::min
#include <cassert>

#include <GL/glew.h>
#include <QDebug>
#include <QtCore/qnamespace.h>  // Needed for Qt::Key enums
#include <QtGui/QKeyEvent>

#include <jumpy_engine/matrix3D.h>
#include <jumpy_engine/radian.h>
#include <jumpy_engine/vector2D.h>
#include <jumpy_engine/vector3D.h>

#include "keyState.h"
#include "window.h"

namespace {
    auto const BASE_VELOCITY = 0.07f;
    auto const SQUARE_ROOT_ZERO_POINT_ZERO_TWO {0.141421356f};
    const math::Vector3D VERTICES[] = {
        {-0.0f, SQUARE_ROOT_ZERO_POINT_ZERO_TWO, 1},
        {-0.1f, -0.1f, 1},
        {+0.1f, -0.1f, 1},
    };
    auto const ANGULAR_MOVEMENT = 10.0f;
    const unsigned int VERTICES_COUNT = sizeof(VERTICES) / sizeof(VERTICES[0]);
    math::Vector2D SHIP_POSITION {0, 0};
    math::Vector2D SHIP_VELOCITY {0, 0};
    float SHIP_ORIENTATION {0.0};
}

namespace game {
    bool Window::allowUserInput()
    {
        return this->underMouse();
    }

    inline void Window::createViewport()
    {
        auto const minimum = std::min(this->width(), this->height());
        math::Vector2D viewport {
            (this->width() / 2.0f) - (minimum / 2.0f),
            (this->height() / 2.0f) - (minimum / 2.0f)
        };
        glViewport(viewport.x, viewport.y, minimum, minimum);
    }

    void Window::initializeGL()
    {
        auto errorCode = glewInit();
        // TODO : Make this a proper logger later
        // Reference: https://youtu.be/yDgbNeYmG7g?t=605
        //
        assert(errorCode == 0);

        glGenBuffers(1, &this->vertexBufferId);
        glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferId);
        // glBufferData allocates and sends the data (points) to RAM
        // GL_DYNAMIC_DRAW - "Please refresh this buffer data over time"
        // NULL - "We will tell you where this RAM's points will be later"
        //
        glBufferData(GL_ARRAY_BUFFER, sizeof(VERTICES), NULL, GL_DYNAMIC_DRAW);
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
        // TODO: Replace with a matrix, later

        math::Vector2D const direction {
            -1 * std::sin(SHIP_ORIENTATION),
            std::cos(SHIP_ORIENTATION),
        };

        if (game::isKeyState(game::Direction::up))
        {
            SHIP_VELOCITY += direction * acceleration;
        }
        if (game::isKeyState(game::Direction::down))
        {
            SHIP_VELOCITY -= direction * acceleration;
        }

    }

    void Window::paintGL()
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Create a viewport
        this->createViewport();

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
        // that the attribute is a float with a size of 3 (because it's a Vector3D).
        //
        glVertexAttribPointer(attributeIndex, math::Vector3D::size, GL_FLOAT, GL_FALSE, 0, 0);

        math::Vector3D transformedVertices[VERTICES_COUNT];
        auto const transform = 
            math::Matrix3D::translate(SHIP_POSITION) *
            math::Matrix3D::rotateZ(math::Radian{SHIP_ORIENTATION});

        for (unsigned int index = 0; index < VERTICES_COUNT; ++index)
        {
            transformedVertices[index] = transform * VERTICES[index];
        }

        // Send data to OpenGL
        glBufferSubData(
            GL_ARRAY_BUFFER,
            0,
            sizeof(transformedVertices),
            transformedVertices
        );

        // Draw the points
        glDrawArrays(GL_TRIANGLES, 0, VERTICES_COUNT);
    }
}
