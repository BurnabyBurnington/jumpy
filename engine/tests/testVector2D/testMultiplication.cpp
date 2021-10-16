#include <cassert>
#include <ctest.h>
#include <vector2D.h>

// TODO: Add tests with a huge float value
// TODO: Add tests to ensure the + operator can be chained repeatedly

CTEST(multiplication_const_operators, test_scalar) {
    auto const first = engine::Vector2D {10, 12};

    auto const vector_1 = first * 2;
    ASSERT_EQUAL(vector_1.x, 20);
    ASSERT_EQUAL(vector_1.y, 24);

    auto const vector_2 = first * -2;
    ASSERT_EQUAL(vector_2.x, -20);
    ASSERT_EQUAL(vector_2.y, -24);
}

CTEST(multiplication_const_operators, test_vector) {
    auto const first = engine::Vector2D {10, 12};
    auto const second = engine::Vector2D {-2, 100};

    auto const vector1 = first * second;

    ASSERT_EQUAL(vector1.x, -20);
    ASSERT_EQUAL(vector1.y, 1200);

    auto const vector2 = second * first;

    ASSERT_EQUAL(vector2.x, -20);
    ASSERT_EQUAL(vector2.y, 1200);
}

CTEST(multiplication_operators, test_scalar) {
    auto first = engine::Vector2D {10, 12};

    auto vector_1 = first * 2;
    ASSERT_EQUAL(vector_1.x, 20);
    ASSERT_EQUAL(vector_1.y, 24);

    auto vector_2 = first * -2;
    ASSERT_EQUAL(vector_2.x, -20);
    ASSERT_EQUAL(vector_2.y, -24);
}

CTEST(multiplication_operators, test_vector) {
    auto first = engine::Vector2D {10, 12};
    auto second = engine::Vector2D {-2, 100};

    auto vector1 = first * second;

    ASSERT_EQUAL(vector1.x, -20);
    ASSERT_EQUAL(vector1.y, 1200);

    auto vector2 = second * first;

    ASSERT_EQUAL(vector2.x, -20);
    ASSERT_EQUAL(vector2.y, 1200);
}
