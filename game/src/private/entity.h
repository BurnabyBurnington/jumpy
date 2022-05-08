#pragma once

#include "types/simple.h"


namespace game {
    class Entity {
        public:
            Entity (game::types::EntityIndex id) : id(id) {}

            friend bool operator<(Entity const &left, Entity const &right) { return left.id < right.id; }

        private:
            game::types::EntityIndex id;
    };
}
