#include "../componentMask.h"
#include "system.h"

namespace game
{
    class World;

    namespace systems
    {
        void System::deregisterEntity(game::Entity entity)
        {
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
    }
}
