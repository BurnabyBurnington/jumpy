#include <cassert>
#include <ctest.h>
#include <vector2D.h>

// TODO: Add tests with a huge int value
// TODO: Add tests to ensure the + operator can be chained repeatedly

// TODO: Is reflexive plus_equal possible in C++ if the types differ?
// Double-check this. Do the same for multiplication, too
//
CTEST(plusEqualOperators, scalar) {
    auto vector1 = math::Vector2D {10, 12};
    vector1 += 2;
    ASSERT_FLOAT_EQUAL(12, vector1.x);
    ASSERT_FLOAT_EQUAL(14, vector1.y);

    auto vector2 = math::Vector2D {10, 12};
    vector2 += -20;
    ASSERT_FLOAT_EQUAL(-10, vector2.x);
    ASSERT_FLOAT_EQUAL(-8, vector2.y);
}

CTEST(plusEqualOperators, vector) {
    auto vector1 = math::Vector2D {10, 12};
    auto vector2 = math::Vector2D {-2, 100};

    vector1 += vector2;
    ASSERT_FLOAT_EQUAL(8, vector1.x);
    ASSERT_FLOAT_EQUAL(112, vector1.y);

    auto vector3 = math::Vector2D {-30, -34};
    auto vector4 = math::Vector2D {4, 300};

    vector4 += vector3;
    ASSERT_FLOAT_EQUAL(-26, vector4.x);
    ASSERT_FLOAT_EQUAL(266, vector4.y);
}
