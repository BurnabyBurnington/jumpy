#include <jumpy_engine/radian.h>

#include <keyState.h>
#include "playerMovement.h"

namespace {
    static const float ANGULAR_MOVEMENT {40};
    static const float REVERSED_ANGULAR_MOVEMENT {-1 * ANGULAR_MOVEMENT};
}

namespace game
{
    namespace systems
    {
        void PlayerMovement::rotateShip(double delta)
        {
            auto rotate = [this](math::Radian const &rotate)
            {
                for (auto &entity : this->registeredEntities)
                {
                    game::componentHandler::Handler<game::components::Transform> transform;
                    this->world->unpack(entity, transform);

                    // TODO: Make this prettier, later. e.g.
                    // `transform.rotate()`, instead of
                    // `transform.component.rotate()`
                    //
                    transform.component->rotate(rotate);
                }
            };

            if (game::isKeyState(game::Direction::left))
            {
                rotate(math::Radian {static_cast<float>(ANGULAR_MOVEMENT * delta)});
            }
            else if (game::isKeyState(game::Direction::right))
            {
                rotate(math::Radian {static_cast<float>(REVERSED_ANGULAR_MOVEMENT * delta)});
            }
        }

        void PlayerMovement::update(double delta)
        {
            // // TODO : Finish
            this->rotateShip(delta);
            // this->updateVelocity(delta);
            // // SHIP_POSITION += SHIP_VELOCITY;
        }
    }
}