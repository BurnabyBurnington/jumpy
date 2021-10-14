#include <vector2D.h>

int main() {
    auto first = Vector2D<int> {10, 12};
    auto second = Vector2D<int> {-2, 100};

    auto vector = first + second;

    assert(vector.x == 8)
    assert(vector.y == 112)

    return 0;
}
