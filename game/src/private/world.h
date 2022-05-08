#pragma once

#include <algorithm>
#include <memory>
#include <vector>

#include "componentManager.h"
#include "entity.h"
#include "entityManager.h"

namespace game
{
    class EntityHandle;

    class World;  // TODO : Not sure if I need this. Probably do.

    // Reference: https://stackoverflow.com/a/11711094/3626104
    class World : public std::enable_shared_from_this<World>
    {
        public:
            template<typename Type>
            void addComponent(Entity const &entity, Type &component)
            {
                auto family = this->getOrCreateComponentFamilyIndex<Type>();
                auto manager = this->componentManagers[family];
                manager->addComponent(entity, component);
            }

            game::EntityHandle createEntity();

        private:
            template<typename Type>
            ComponentManager<Type> *getComponentManager()
            {
                unsigned int family = this->getOrCreateComponentFamilyIndex<Type>();

                if (family >= this->componentManagers.size()) {
                    // Make room for the new family
                    this->componentManagers.resize(family + 1);
                }

                auto raw = this->componentManagers[family].get();

                return static_cast<ComponentManager<Type>*>(raw);
            }

            template<typename Type>
            unsigned int getOrCreateComponentFamilyIndex(Type manager)
            {
                auto iterator = std::find(
                    this->componentManagers.begin(),
                    this->componentManagers.end(),
                    manager
                );

                if (iterator == this->componentManagers.cend())
                {
                    return this->componentManagers.size();
                }

                return std::distance(this->componentManagers.begin(), iterator);
            }

            std::unique_ptr<game::EntityManager> entityManager;
            std::vector<std::unique_ptr<game::BaseComponentManager>> componentManagers;
    };
}
