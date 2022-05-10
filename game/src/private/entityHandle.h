#pragma once

#include <memory>

#include "componentHandler.h"
#include "entity.h"
#include "world.h"

namespace game
{
    class Entity;

    class EntityHandle
    {
        public:
            EntityHandle(game::World *world, game::Entity entity) : world(world), entity(entity) {}

            template<typename Type>
            void addComponent(Type &&component) {
                this->world->addComponent(entity, component);
            }

        private:
            // TODO: Consider using a shared_ptr or something later
            game::World* world;
            game::Entity entity;
    };
}
