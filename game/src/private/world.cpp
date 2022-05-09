#include "entityHandle.h"
#include "world.h"

namespace game
{
    void World::addSystem(std::unique_ptr<game::systems::System> system)
    {
        system->registerWorld(this);
        this->systems.push_back(std::move(system));
    }

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

    void World::updateEntityMask(game::Entity const &entity, game::componentMask::Mask const &old) {
        auto newMask = this->entityMasks[entity];

        for (auto &system : this->systems) {
            auto current = system->getSignature();

            if (newMask.isNewMatch(old, current)) {
                // We match but didn't match before
                system->registerEntity(entity);
            } else if (newMask.isNoLongerMatched(old, current)) {
                system->deregisterEntity(entity);
            }
        }
    }
}
