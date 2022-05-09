#pragma once

#include <type_traits>

#include <jumpy_engine/vector2D.h>

#include "types/simple.h"


namespace
{
    static int FAMILY_COUNTER = 0;
}

namespace game
{
    namespace components
    {
        using FamilyIndex = unsigned int;

        template<typename ComponentType>
        class Component
        {
            public:
                static inline FamilyIndex family() {
                    static FamilyIndex family = FAMILY_COUNTER++;

                    return family;
                }
        };

        class Health : public Component<Health>
        {
            public:
                Health() : current(0), max(0) {}
                Health(int current, int max) : current(current), max(max) {}

                game::types::Health current;
                game::types::Health max;
        };

        class Motion : public Component<Motion>
        {
            math::Vector2D velocity;
            math::Vector2D acceleration;
        };

        class Transform : public Component<Transform>
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
