#pragma once

#include <iostream>

#include "components.h"

namespace game
{
    namespace componentHandler
    {
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

        get

        // // TODO : Figure out what to do about this code
        // template<typename Type>
        // BaseHandler get(Type component)
        // {
        //     return {};
        // }
        //
        // // template<>
        // // HealthHandler get<game::components::Health>(game::components::Health component)
        // // {
        // //     return {component};
        // // }
    }
}
