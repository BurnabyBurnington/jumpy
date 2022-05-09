#pragma once

#include <iostream>

#include <keyState.h>
#include "system.h"


namespace game
{
    namespace systems
    {
        class Joystick : public System
        {
            public:
                Joystick() {
                    this->signature.addComponent<game::components::Motion>();
                    this->signature.addComponent<game::components::Transform>();
                }

                void rotateShip(double delta)
                {
                    if (game::isKeyState(game::Direction::left))
                    {
                        std::cout << "left: " << delta << '\n';
                    }
                    else if (game::isKeyState(game::Direction::right))
                    {
                        std::cout << "right: " << delta << '\n';
                    }
                }

                virtual void update(double delta) override
                {
                    std::cout << "UPdating: " << delta << '\n';
                    // // TODO : Finish
                    // this->rotateShip(delta);
                    // this-> updateVelocity(delta);
                    // // SHIP_POSITION += SHIP_VELOCITY;
                }
        };
    }
}
