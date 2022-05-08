#pragma once

#include <jumpy_engine/vector2D.h>


namespace game
{
    namespace components
    {
        struct Joystick
        {
        };

        struct Health
        {
            int current;
            int max;
        };

        struct Motion
        {
            math::Vector2D velocity;
            math::Vector2D acceleration;
        };

        struct Transform
        {
            int x;
            int y;
        };
    }
}
