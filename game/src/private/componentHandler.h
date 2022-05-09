#pragma once

#include <memory>
#include <iostream>

#include "components/components.h"
#include "types/simple.h"

namespace game
{
    namespace componentHandler
    {
        class BaseHandler;

        using HandlePointer = std::unique_ptr<BaseHandler>;

        class BaseHandler
        {
            public:
                BaseHandler() = default;
        };

        template<typename Type>
        class Handler : public BaseHandler
        {
            public:
                Handler() = default;
                Handler(Type &component) : component(component) {}

                Type component;
        };

        // template<>
        // class Handler<game::components::Health>
        // {
        //     public:
        //         game::types::Health get() { return this->component.current; }
        //
        //         void heal(unsigned int amount)
        //         {
        //             auto value = this->component.current + amount;
        //
        //             if (value > this->component.max)
        //             {
        //                 this->component.current = this->component.max;
        //             }
        //             else
        //             {
        //                 this->component.current = value;
        //             }
        //         }
        //
        //     private:
        //         game::components::Health component;
        // };

        // // TODO: Remove this useless function later
        // HandlePointer get(game::components::Health)
        // {
        //     return std::make_unique<BaseHandler>();
        // }
    }
}
