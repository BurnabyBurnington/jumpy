#include <cassert>
#include <ctest.h>
#include <vector2D.h>

// TODO: Add tests with a huge float value
// TODO: Add tests to ensure the + operator can be chained repeatedly

CTEST(vectorMultiplicationConst, scalar) {
    auto const first = math::Vector2D {10, 12};

    auto const vector1 = first * 2;
    ASSERT_FLOAT_EQUAL(20, vector1.x);
    ASSERT_FLOAT_EQUAL(24, vector1.y);

    auto const vector2 = first * -2;
    ASSERT_FLOAT_EQUAL(-20, vector2.x);
    ASSERT_FLOAT_EQUAL(-24, vector2.y);
}

CTEST(vectorMultiplicationConst, scalarReflexivity) {
    auto const first = math::Vector2D {10, 12};
    auto const vector3 = first * -100;
    auto const vector4 = -100 * first;

    ASSERT_FLOAT_EQUAL(-1000, vector3.x);
    ASSERT_FLOAT_EQUAL(-1200, vector3.y);
    ASSERT_FLOAT_EQUAL(-1000, vector4.x);
    ASSERT_FLOAT_EQUAL(-1200, vector4.y);
    ASSERT_FLOAT_EQUAL(vector3.x, vector4.x);
    ASSERT_FLOAT_EQUAL(vector3.y, vector4.y);
}

CTEST(vectorMultiplicationConst, vector) {
    auto const first = math::Vector2D {10, 12};
    auto const second = math::Vector2D {-2, 100};

    auto const vector1 = first * second;

    ASSERT_FLOAT_EQUAL(-20, vector1.x);
    ASSERT_FLOAT_EQUAL(1200, vector1.y);

    auto const vector2 = second * first;

    ASSERT_FLOAT_EQUAL(-20, vector2.x);
    ASSERT_FLOAT_EQUAL(1200, vector2.y);
}

CTEST(additionConstOperators, vectorReflexivity) {
    auto const first = math::Vector2D {10, 12};
    auto const second = math::Vector2D {25, -35};
    auto const result1 = first * second;
    auto const result2 = second * first;

    ASSERT_FLOAT_EQUAL(250, result1.x);
    ASSERT_FLOAT_EQUAL(-420, result1.y);
    ASSERT_FLOAT_EQUAL(250, result2.x);
    ASSERT_FLOAT_EQUAL(-420, result2.y);
    ASSERT_FLOAT_EQUAL(result1.x, result2.x);
    ASSERT_FLOAT_EQUAL(result1.y, result2.y);
}

CTEST(vectorMultiplication, scalar) {
    auto first = math::Vector2D {10, 12};

    auto vector1 = first * 2;
    ASSERT_FLOAT_EQUAL(20, vector1.x);
    ASSERT_FLOAT_EQUAL(24, vector1.y);

    auto vector2 = first * -2;
    ASSERT_FLOAT_EQUAL(-20, vector2.x);
    ASSERT_FLOAT_EQUAL(-24, vector2.y);
}

CTEST(vectorMultiplication, scalarReflexivity) {
    auto first = math::Vector2D {10, 12};
    auto vector3 = first * -100;
    auto vector4 = -100 * first;

    ASSERT_FLOAT_EQUAL(-1000, vector3.x);
    ASSERT_FLOAT_EQUAL(-1200, vector3.y);
    ASSERT_FLOAT_EQUAL(-1000, vector4.x);
    ASSERT_FLOAT_EQUAL(-1200, vector4.y);
    ASSERT_FLOAT_EQUAL(vector3.x, vector4.x);
    ASSERT_FLOAT_EQUAL(vector3.y, vector4.y);
}

CTEST(vectorMultiplication, vector) {
    auto first = math::Vector2D {10, 12};
    auto second = math::Vector2D {-2, 100};

    auto vector1 = first * second;

    ASSERT_FLOAT_EQUAL(-20, vector1.x);
    ASSERT_FLOAT_EQUAL(1200, vector1.y);

    auto vector2 = second * first;

    ASSERT_FLOAT_EQUAL(-20, vector2.x);
    ASSERT_FLOAT_EQUAL(1200, vector2.y);
}

CTEST(additionOperators, vectorReflexivity) {
    auto first = math::Vector2D {10, 12};
    auto second = math::Vector2D {25, -35};
    auto result1 = first * second;
    auto result2 = second * first;

    ASSERT_FLOAT_EQUAL(250, result1.x);
    ASSERT_FLOAT_EQUAL(-420, result1.y);
    ASSERT_FLOAT_EQUAL(250, result2.x);
    ASSERT_FLOAT_EQUAL(-420, result2.y);
    ASSERT_FLOAT_EQUAL(result1.x, result2.x);
    ASSERT_FLOAT_EQUAL(result1.y, result2.y);
}
