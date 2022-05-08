#pragma once

#include <map>


// TODO: Consider optimizing (e.g. using const &Entity, etc
namespace game
{
    struct Entity;

    class BaseComponentManager
    {
        public:
            BaseComponentManager() {};
    };

    // template <typename Type>
    // struct ComponentData {
    //     unsigned int size = 1;
    //     std::array<Type, 1024> data;
    // };

    // TODO: Possibly remove this / simplify in the future
    struct ComponentInstance {
        unsigned int index;
    };

    // TODO : Finish this
    template<typename Type>
    class ComponentManager : public BaseComponentManager
    {
        public:
            ComponentInstance add(Entity entity, Type& component);
        //
        //     Type* lookup(Entity entity);
        //
        //     void destroy(Entity entity);
        //
        // private:
        //     ComponentData data;
        //     EntityMap entityMap;
    };

    // ComponentInstance ComponentManager::add(Entity entity, Type& component){
    //     ComponentInstance newInstance { this->data.size };
    //     this->data.data[newInstance] = component;
    //     this->entityMap[entity] = newInstance;
    //
    //     this->data.size++;
    //
    //     return newInstance;
    // }

    // Type* lookup(Entity entity)
    // {
    //     ComponentInstance instance = this->entityMap.getInstance(entity);
    //
    //     return &this->data.data[instance.index];
    // }

    // void destroy(Entity entity){
    //     ComponentInstance instance = this->entityMap[entity];
    //     ComponentInstance previous = this->data.size - 1;
    //     componentData[instance] = this->data.data[previous];
    //
    //     this->entityMap.erase(entity);
    //     componentData.size--;
    //
    //     // Update the map for the moved entity as well
    //     Entity movedEntity = getEntityByComponentInstance(previous);
    //     this->entityMap[movedEntity] = instance;
    // }
}
