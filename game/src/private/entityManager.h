#pragma once

#include "types/simple.h"


namespace game
{
    class EntityManager
    {
        public:
            game::types::EntityIndex getNextIndex() {
                this->current += 1;

                return this->current;
            }

        private:
            game::types::EntityIndex current {0};
    };
}
