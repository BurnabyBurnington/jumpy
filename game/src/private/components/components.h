#pragma once

#include <iostream>

#include <type_traits>

#include <jumpy_engine/matrix3D.h>
#include <jumpy_engine/radian.h>
#include <jumpy_engine/vector2D.h>

#include "types/simple.h"


namespace
{
    static int FAMILY_COUNTER {0};
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
            math::Matrix3D transform;

            public:
                // TODO: Consider strong types, here
                void rotate(math::Radian const &radians)
                {
                    std::cout << "ROTATING here " << radians.get() << "\n";
                    this->transform.rotateZ(radians);
                }
        };

        // TODO : Remove later
        // template <typename Type>
        // static FamilyIndex getFamilyIndex() {
        //     return Type::family();
        // }
    }
}
