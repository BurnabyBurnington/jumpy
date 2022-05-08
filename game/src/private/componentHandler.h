#pragma once

#include <memory>
#include <iostream>

#include "types/simple.h"
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
                Handler(Type &component) : component(component) {}

            protected:
                Type component;
        };

        template<>
        class Handler<game::components::Health>
        {
            public:
                Handler(game::components::Health &component) : component(component) {}

                game::types::Health get() { return this->component.current; }

                void heal(unsigned int amount)
                {
                    auto value = this->component.current + amount;

                    if (value > this->component.max)
                    {
                        this->component.current = this->component.max;
                    }
                    else
                    {
                        this->component.current = value;
                    }
                }

            private:
                game::components::Health component;
        };

        // // TODO: Remove this useless function later
        // HandlePointer get(game::components::Health)
        // {
        //     return std::make_unique<BaseHandler>();
        // }
    }
}
