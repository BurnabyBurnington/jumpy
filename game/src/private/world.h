#pragma once

#include "entity.h"
#include "entityHandle.h"
#include "entityManager.h"

namespace game
{
    class World;

    // Reference: https://stackoverflow.com/a/11711094/3626104
    class World : public std::enable_shared_from_this<World>
    {
        public:
            void addComponent(int &component)
            {
            }

            game::EntityHandle createEntity()
            {
                game::Entity entity {this->entityManager->getNextIndex()};

                // XXX : Possibly it's overkill to pass a shared_ptr
                return game::EntityHandle {this->shared_from_this(), entity};
            }

        private:
            game::EntityManager *entityManager;
    };
}
