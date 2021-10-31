#include <cassert>
#include <ctest.h>
#include <vector2D.h>

// TODO: Add tests with a huge float value
// TODO: Add tests to ensure the + operator can be chained repeatedly

CTEST(vectorMultiplicationConst, scalar) {
    auto const first = math::Vector2D {10, 12};

    auto const vector_1 = first * 2;
    ASSERT_EQUAL(20, vector_1.x);
    ASSERT_EQUAL(24, vector_1.y);

    auto const vector_2 = first * -2;
    ASSERT_EQUAL(-20, vector_2.x);
    ASSERT_EQUAL(-24, vector_2.y);
}

CTEST(vectorMultiplicationConst, vector) {
    auto const first = math::Vector2D {10, 12};
    auto const second = math::Vector2D {-2, 100};

    auto const vector1 = first * second;

    ASSERT_EQUAL(-20, vector1.x);
    ASSERT_EQUAL(1200, vector1.y);

    auto const vector2 = second * first;

    ASSERT_EQUAL(-20, vector2.x);
    ASSERT_EQUAL(1200, vector2.y);
}

CTEST(vectorMultiplication, scalar) {
    auto first = math::Vector2D {10, 12};

    auto vector_1 = first * 2;
    ASSERT_EQUAL(20, vector_1.x);
    ASSERT_EQUAL(24, vector_1.y);

    auto vector_2 = first * -2;
    ASSERT_EQUAL(-20, vector_2.x);
    ASSERT_EQUAL(-24, vector_2.y);
}

CTEST(vectorMultiplication, vector) {
    auto first = math::Vector2D {10, 12};
    auto second = math::Vector2D {-2, 100};

    auto vector1 = first * second;

    ASSERT_EQUAL(-20, vector1.x);
    ASSERT_EQUAL(1200, vector1.y);

    auto vector2 = second * first;

    ASSERT_EQUAL(-20, vector2.x);
    ASSERT_EQUAL(1200, vector2.y);
}