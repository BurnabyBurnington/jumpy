#include <vector2D.h>
#include <cassert>
#include "ctest.h"

// TODO: Add tests with a huge int value
// TODO: Add tests to ensure the + operator can be chained repeatedly

CTEST(const_operators, test_scalar) {
    auto const first = engine::Vector2D {10, 12};

    auto const vector_1 = first + 2;
    ASSERT_EQUAL(vector_1.x, 12);
    ASSERT_EQUAL(vector_1.y, 14);

    auto const vector_2 = first + -20;
    ASSERT_EQUAL(vector_2.x, -10);
    ASSERT_EQUAL(vector_2.y, -8);
}

CTEST(const_operators, test_vector) {
    auto const first = engine::Vector2D {10, 12};
    auto const second = engine::Vector2D {-2, 100};

    auto const vector = first + second;

    ASSERT_EQUAL(vector.x, 8);
    ASSERT_EQUAL(vector.y, 112);
}

CTEST(operators, test_scalar) {
    auto first = engine::Vector2D {10, 12};

    auto vector_1 = first + 2;
    ASSERT_EQUAL(vector_1.x, 12);
    ASSERT_EQUAL(vector_1.y, 14);

    auto vector_2 = first + -20;
    ASSERT_EQUAL(vector_2.x, -10);
    ASSERT_EQUAL(vector_2.y, -8);
}

CTEST(operators, test_vector) {
    auto first = engine::Vector2D {10, 12};
    auto second = engine::Vector2D {-2, 100};

    auto vector = first + second;

    ASSERT_EQUAL(vector.x, 8);
    ASSERT_EQUAL(vector.y, 112);
}
