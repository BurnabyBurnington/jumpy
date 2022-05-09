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

    void World::initialize()
    {
        for (auto &system : this->systems)
        {
            system->initialize();
        }
    }

    void World::update(double delta)
    {
        for (auto &system : this->systems)
        {
            system->update(delta);
        }
    }
}

