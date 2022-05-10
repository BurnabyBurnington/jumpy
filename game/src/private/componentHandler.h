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
                // TODO: Make the default constructor deleted, probably
                Handler() = default;
                Handler(Type *component) : component(component) {}

                Type *component;
        };
    }
}
