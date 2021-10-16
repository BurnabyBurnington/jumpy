#include <cassert>
#include <ctest.h>
#include <vector2D.h>

// TODO: Add tests with a huge int value
// TODO: Add tests to ensure the + operator can be chained repeatedly

// TODO: Is reflexive plus_equal possible in C++ if the types differ?
// Double-check this. Do the same for multiplication, too
//
CTEST(plus_equal_operators, test_scalar) {
    auto vector_1 = engine::Vector2D {10, 12};
    vector_1 += 2;
    ASSERT_EQUAL(12, vector_1.x);
    ASSERT_EQUAL(14, vector_1.y);

    auto vector_2 = engine::Vector2D {10, 12};
    vector_2 += -20;
    ASSERT_EQUAL(-10, vector_2.x);
    ASSERT_EQUAL(-8, vector_2.y);
}

CTEST(plus_equal_operators, test_vector) {
    auto vector1 = engine::Vector2D {10, 12};
    auto vector2 = engine::Vector2D {-2, 100};

    vector1 += vector2;
    ASSERT_EQUAL(8, vector1.x);
    ASSERT_EQUAL(112, vector1.y);

    auto vector3 = engine::Vector2D {-30, -34};
    auto vector4 = engine::Vector2D {4, 300};

    vector4 += vector3;
    ASSERT_EQUAL(-24, vector3.x);
    ASSERT_EQUAL(266, vector3.y);
}
