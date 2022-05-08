#pragma once

#include "types/simple.h"


namespace game
{
    class EntityManager
    {
        public:
            game::types::EntityIndex getNextIndex() {
                current += 1;
                return current;
            }

        private:
            game::types::EntityIndex current {0};
    };
}
