#pragma once

#include <memory>

#include "entity.h"
#include "world.h"

namespace game
{
    class Entity;

    class EntityHandle
    {
        public:
            EntityHandle(std::shared_ptr<game::World> world, game::Entity entity) : world(world), entity(entity) {}

            template<typename ComponentType>
            void addComponent(ComponentType component) {
                this->world->addComponent(entity, component);
            }

        private:
            // XXX : Possibly remove this shared_ptr. Because IIRC shared_ptr
            // has overhead and it's unlikely that `world` will become a
            // dangling pointer.
            //
            std::shared_ptr<game::World> world;
            game::Entity entity;
    };
}
