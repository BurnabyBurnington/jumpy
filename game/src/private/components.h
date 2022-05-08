#pragma once

#include <jumpy_engine/vector2D.h>


namespace
{
    int FAMILY_COUNTER {0};
}

namespace game
{
    namespace components
    {
        using FamilyIndex = unsigned int;

        class Component
        {
            public:
                static inline FamilyIndex family() {
                    FAMILY_COUNTER++;

                    return FAMILY_COUNTER;
                }
        };

        class Joystick : public Component
        {
        };

        class Health : public Component
        {
            public:
                int current;
                int max;
        };

        class Motion : public Component
        {
            math::Vector2D velocity;
            math::Vector2D acceleration;
        };

        class Transform : public Component
        {
            int x;
            int y;
        };

        // TODO : Remove later
        // template <typename Type>
        // static FamilyIndex getFamilyIndex() {
        //     return Type::family();
        // }
    }
}
