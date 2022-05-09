#include <bitset>
#include <vector>

#include "../entity.h"
#include "../world.h"

namespace game
{
    class System {
        public:
            // Initialize the System — This happens *before* the game starts but
            // *after* the world has been registered.
            //
            virtual void init() {};

            virtual void update(int delta) {};

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
            void deRegisterEntity(game::Entity entity) {
                for (
                    auto iterator = this->registeredEntities.begin();
                    iterator != this->registeredEntities.end();
                    ++iterator
                ) {
                    game::Entity found = *iterator;

                    if (found == entity) {
                        this->registeredEntities.erase(iterator);

                        return;
                    }
                }
            }

    private:
      // Specifies which components our system cares about — its size should =
      // the number of different components.
      //
      // Important:
      //    This assumes there's only 32 unique component families, maximum.
      //    Otherwise, more need to be added.
      //
      std::bitset<32> systemSignature;

      // These entities fit the systemSignature and should be iterated upon for any functionality
      std::vector<game::Entity> registeredEntities;

      // Reference to our parent world
      game::World * world;
    };
}
