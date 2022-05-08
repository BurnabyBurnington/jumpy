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

        class HealthHandler : public BaseHandler
        {
            public:
                HealthHandler(game::components::Health health) : health(health) {}

                void heal(unsigned int amount)
                {
                    std::cout << "AMOUNT: " << amount << '\n';
                }

            private:
                game::components::Health health;
        };

        // // TODO: Remove this useless function later
        // HandlePointer get()
        // {
        //     return std::make_unique<BaseHandler>();
        // }
    }
}
