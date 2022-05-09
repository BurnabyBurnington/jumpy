#include <keyState.h>
#include "system.h"


namespace game
{
    namespace systems
    {
        class Joystick : public game::System
        {
            public:
                void rotateShip(double delta)
                {
                    if (game::isKeyState(game::Direction::left))
                    {
                        this->tiltLeft(delta);
                    }
                    else if (game::isKeyState(game::Direction::right))
                    {
                        this->tiltRight(delta);
                    }
                }

                virtual void update(double delta)
                {
                    // TODO : Finish
                    this->rotateShip(delta);
                    this-> updateVelocity(delta);
                    // SHIP_POSITION += SHIP_VELOCITY;
                }

            private:
                void tiltLeft(double delta) {}
                void tiltRight(double delta) {}
        };
    }
}
