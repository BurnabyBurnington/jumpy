#include <vector2D.h>
#include <cassert>

int main() {
    auto first = engine::Vector2D {10, 12};
    auto second = engine::Vector2D {-2, 100};

    auto vector = first + second;

    assert(vector.x == 8);
    assert(vector.y == 112);

    return 0;
}
