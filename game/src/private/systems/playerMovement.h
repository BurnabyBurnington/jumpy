#pragma once

#include "../world.h"
#include "system.h"

namespace game
{
    namespace systems
    {
        class PlayerMovement : public System
        {
            public:
                PlayerMovement() {
                    // this->signature.addComponent<game::components::Motion>();
                    this->signature.addComponent<game::components::Transform>();
                }

                void rotateShip(double delta);

                virtual void update(double delta) override;
        };
    }
}
