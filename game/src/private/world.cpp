#include "entityHandle.h"
#include "world.h"

namespace game
{
    game::EntityHandle World::createEntity()
    {
        game::Entity entity {this->entityManager->getNextIndex()};

        // XXX : Possibly it's overkill to pass a shared_ptr
        return game::EntityHandle {this->shared_from_this(), entity};
    }
}

