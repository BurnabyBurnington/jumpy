#include "entityHandle.h"
#include "world.h"

namespace game
{
    game::EntityHandle World::createEntity()
    {
        game::Entity entity {this->entityManager->getNextIndex()};

        // TODO : Possibly needs a shared_ptr or something
        return game::EntityHandle {this, entity};
    }
}

