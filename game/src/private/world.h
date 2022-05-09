#pragma once

#include <algorithm>
#include <map>
#include <memory>
#include <utility>
#include <vector>

#include "componentHandler.h"
#include "componentManager.h"
#include "componentMask.h"
#include "components/components.h"
#include "entity.h"
#include "entityManager.h"
#include "systems/system.h"

namespace game
{
    class EntityHandle;

    class World;  // TODO : Not sure if I need this. Probably do.

    // Reference: https://stackoverflow.com/a/11711094/3626104
    class World : public std::enable_shared_from_this<World>
    {
        public:
            // TODO: Add member initialization
            World()
            {
                this->entityManager = std::make_unique<game::EntityManager>();
            }

            template<typename Type>
            void addComponent(Entity const &entity, Type &component)
            {
                auto manager = this->getComponentManager<Type>();
                manager->add(entity, component);

                auto previous = this->entityMasks[entity];
                this->entityMasks[entity].addComponent<Type>();
                this->updateEntityMask(entity, previous);
            }

            void addSystem(std::unique_ptr<game::systems::System> system);

            game::EntityHandle createEntity();

            void initialize();

            void render();

            // TODO: Make this work with multiple handle later, maybe
            //
            //       Reference: https://github.com/taurheim/NomadECS/blob/70195daa69f4f108e388c74fa6e0b1071f7a01a7/src/world.h#L81-L97
            //
            template <typename Type>
            void unpack(Entity entity, game::componentHandler::Handler<Type> &handle)
            {
                auto manager = this->getComponentManager<Type>();
                auto component = manager->lookup(entity);

                // TODO: Make this work with a generic component handler
                handle = game::componentHandler::Handler<Type>(*component);
                // handle = game::transformHandler::Handler(&component);
                // handle = game::transformHandler::Handler(*component);
                // handle.component = *component;
            }

            void update(double delta);

            void updateEntityMask(Entity const &entity, game::componentMask::Mask const &old);

            // TODO: Make this method private, later
            template<typename Type>
            ComponentManager<Type> *getComponentManager()
            {
                // TODO : Replace this hard-coded value, later
                auto family = game::components::Health::family();
                // auto family = Type::family();

                if (family >= this->componentManagers.size()) {
                    // Make room for the new family
                    this->componentManagers.resize(family + 1);
                }

                if (!componentManagers[family]) {
                    // Initialize the new manager
                    componentManagers[family] = std::make_unique<ComponentManager<Type>>();
                }

                auto raw = this->componentManagers[family].get();

                return static_cast<ComponentManager<Type>*>(raw);
            }

        private:
            // TODO : Remove?
            // template<typename Type>
            // unsigned int getOrCreateComponentFamilyIndex()
            // {
            //     auto iterator = std::find(
            //         this->componentManagers.begin(),
            //         this->componentManagers.end(),
            //         Type
            //     );
            //
            //     if (iterator == this->componentManagers.cend())
            //     {
            //         return this->componentManagers.size();
            //     }
            //
            //     return std::distance(this->componentManagers.begin(), iterator);
            // }

            std::map<Entity, game::componentMask::Mask> entityMasks;
            std::unique_ptr<game::EntityManager> entityManager;
            std::vector<std::unique_ptr<game::BaseComponentManager>> componentManagers;
            std::vector<std::unique_ptr<game::systems::System>> systems;
    };
}
