#pragma once

#include <bitset>
#include <vector>

#include "../componentMask.h"
#include "../entity.h"

namespace game
{
    class World;

    namespace systems
    {
        class System {
            public:
                System() = default;
                virtual ~System() = default;

                // Initialize the System — This happens *before* the game
                // starts but *after* the world has been registered.
                //
                virtual void initialize() {};

                game::componentMask::Mask getSignature() { return this->signature; }

                #pragma GCC diagnostic push
                #pragma GCC diagnostic ignored "-Wunused-parameter"
                virtual void update(double delta) {};
                #pragma GCC diagnostic pop

                virtual void render() {};

                // Add a reference to the parent world
                void registerWorld(game::World * world) {
                    this->world = world;
                }

                // This entity fits our current requirements
                void registerEntity(game::Entity entity) {
                    this->registeredEntities.push_back(entity);
                }

                // This entity has stopped fitting our current requirements
                void deregisterEntity(game::Entity entity);

        protected:
            // Specifies which components our system cares about — its size should =
            // the number of different components.
            //
            // Important:
            //    This assumes there's only 32 unique component families, maximum.
            //    Otherwise, more need to be added.
            //
            game::componentMask::Mask signature;

            // These entities fit the systemSignature and should be iterated upon for any functionality
            std::vector<game::Entity> registeredEntities;

            // Reference to our parent world
            game::World * world;
        };
    }
}
