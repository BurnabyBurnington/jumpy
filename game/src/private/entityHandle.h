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
            void addComponent(Type component) {
                this->world->addComponent(entity, component);

                // TODO: Remove this bad code later
                component->current = 30;
                // return game::componentHandler::get();
            }

        private:
            // TODO: Consider using a shared_ptr or something later
            game::World* world;
            game::Entity entity;
    };
}
