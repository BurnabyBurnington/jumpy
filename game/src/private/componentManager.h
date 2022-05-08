#pragma once

#include <map>

#include "entity.h"

// TODO: Consider optimizing (e.g. using const &Entity, etc
namespace game
{
    using ComponentInstance = unsigned int;

    class BaseComponentManager
    {
    };

    template <typename Type>
    struct ComponentData {
        unsigned int size = 0;
        // TODO: This means we can only have a max of 1024 components, total
        // This system will need to be changed when scaling becomes an issue.
        //
        std::array<Type, 1024> data;
    };

    // TODO : Finish this
    template<typename Type>
    class ComponentManager : public BaseComponentManager
    {
        public:
            ComponentManager<Type>() {}

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
