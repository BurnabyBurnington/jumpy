#pragma once

#include <memory>
#include <iostream>

#include "components.h"

namespace game
{
    namespace componentHandler
    {
        class BaseHandler;

        using HandlePointer = std::unique_ptr<BaseHandler>;

        class BaseHandler
        {
        };

        template<typename Type>
        class Handler : public BaseHandler
        {
            public:
                Handler(Type component) : component(component) {}

            protected:
                Type component;
        };

        template<>
        class Handler<game::components::Health>
        {
            public:
                void heal(unsigned int amount)
                {
                    std::cout << "AMOUNT: " << amount << '\n';
                }
        };

        // // TODO: Remove this useless function later
        // HandlePointer get(game::components::Health)
        // {
        //     return std::make_unique<BaseHandler>();
        // }
    }
}
