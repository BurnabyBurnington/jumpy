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
            EntityHandle(std::shared_ptr<game::World> world, game::Entity entity) : world(world), entity(entity) {}

            template<typename Type>
            game::componentHandler::HandlePointer addComponent(Type component) {
                this->world->addComponent(entity, component);

                return game::componentHandler::get();
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
