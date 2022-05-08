#pragma once

#include <map>

#include "entity.h"

// TODO: Consider optimizing (e.g. using const &Entity, etc
namespace game
{
    using ComponentInstance = unsigned int;

    class BaseComponentManager
    {
        public:
            BaseComponentManager() {};
    };

    template <typename Type>
    struct ComponentData {
        unsigned int size = 1;
        std::array<Type, 1024> data;
    };

    // TODO : Finish this
    template<typename Type>
    class ComponentManager : public BaseComponentManager
    {
        public:
            ComponentInstance add(Entity entity, Type& component)
            {
                ComponentInstance newInstance { this->data.size };
                this->data.data[newInstance] = component;
                this->entityMap[entity] = newInstance;

                this->data.size++;

                return newInstance;
            }

        private:
            ComponentData<Type> data {};
            std::map<Entity, ComponentInstance> entityMap {};
    };
}
