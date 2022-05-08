#include <cassert>
#include <ctest.h>

#include <jumpy_engine/vector2D.h>

// TODO: Add tests with a huge int value
// TODO: Add tests to ensure the + operator can be chained repeatedly

CTEST(additionConstOperators, scalar) {
    auto const first = math::Vector2D {10, 12};

    auto const vector1 = first + 2;
    ASSERT_FLOAT_EQUAL(12, vector1.x);
    ASSERT_FLOAT_EQUAL(14, vector1.y);

    auto const vector2 = first + -20;
    ASSERT_FLOAT_EQUAL(-10, vector2.x);
    ASSERT_FLOAT_EQUAL(-8, vector2.y);
}

CTEST(additionConstOperators, scalarReflexivity) {
    auto const first = math::Vector2D {10, 12};
    auto const vector3 = first + -100;
    auto const vector4 = -100.0f + first;

    ASSERT_FLOAT_EQUAL(-90, vector3.x);
    ASSERT_FLOAT_EQUAL(-88, vector3.y);
    ASSERT_FLOAT_EQUAL(-90, vector4.x);
    ASSERT_FLOAT_EQUAL(-88, vector4.y);
    ASSERT_FLOAT_EQUAL(vector3.x, vector4.x);
    ASSERT_FLOAT_EQUAL(vector3.y, vector4.y);
}

CTEST(additionConstOperators, vector) {
    auto const first = math::Vector2D {10, 12};
    auto const second = math::Vector2D {-2, 100};

    auto const vector1 = first + second;

    ASSERT_FLOAT_EQUAL(8, vector1.x);
    ASSERT_FLOAT_EQUAL(112, vector1.y);

    auto const vector2 = second + first;

    ASSERT_FLOAT_EQUAL(8, vector2.x);
    ASSERT_FLOAT_EQUAL(112, vector2.y);
}

CTEST(additionConstOperators, vectorReflexivity) {
    auto const first = math::Vector2D {10, 12};
    auto const second = math::Vector2D {25, -35};
    auto const result1 = first + second;
    auto const result2 = second + first;

    ASSERT_FLOAT_EQUAL(35, result1.x);
    ASSERT_FLOAT_EQUAL(-23, result1.y);
    ASSERT_FLOAT_EQUAL(35, result2.x);
    ASSERT_FLOAT_EQUAL(-23, result2.y);
    ASSERT_FLOAT_EQUAL(result1.x, result2.x);
    ASSERT_FLOAT_EQUAL(result1.y, result2.y);
}

// TODO: Is reflexive addition possible in C++ if the types differ?
// Double-check this. Do the same for multiplication, too
//
CTEST(additionOperators, scalar) {
    auto first = math::Vector2D {10, 12};

    auto vector1 = first + 2;
    ASSERT_FLOAT_EQUAL(12, vector1.x);
    ASSERT_FLOAT_EQUAL(14, vector1.y);

    auto vector2 = first + -20;
    ASSERT_FLOAT_EQUAL(-10, vector2.x);
    ASSERT_FLOAT_EQUAL(-8, vector2.y);
}

CTEST(additionOperators, scalarReflexivity) {
    auto first = math::Vector2D {10, 12};
    auto vector3 = first + -100;
    auto vector4 = -100.0f + first;

    ASSERT_FLOAT_EQUAL(-90, vector3.x);
    ASSERT_FLOAT_EQUAL(-88, vector3.y);
    ASSERT_FLOAT_EQUAL(-90, vector4.x);
    ASSERT_FLOAT_EQUAL(-88, vector4.y);
    ASSERT_FLOAT_EQUAL(vector3.x, vector4.x);
    ASSERT_FLOAT_EQUAL(vector3.y, vector4.y);
}

CTEST(additionOperators, vector) {
    auto first = math::Vector2D {10, 12};
    auto second = math::Vector2D {-2, 100};

    auto vector1 = first + second;

    ASSERT_FLOAT_EQUAL(8, vector1.x);
    ASSERT_FLOAT_EQUAL(112, vector1.y);

    auto vector2 = second + first;

    ASSERT_FLOAT_EQUAL(8, vector2.x);
    ASSERT_FLOAT_EQUAL(112, vector2.y);
}

CTEST(additionOperators, vectorReflexivity) {
    auto first = math::Vector2D {10, 12};
    auto second = math::Vector2D {25, -35};
    auto result1 = first + second;
    auto result2 = second + first;

    ASSERT_FLOAT_EQUAL(35, result1.x);
    ASSERT_FLOAT_EQUAL(-23, result1.y);
    ASSERT_FLOAT_EQUAL(35, result2.x);
    ASSERT_FLOAT_EQUAL(-23, result2.y);
    ASSERT_FLOAT_EQUAL(result1.x, result2.x);
    ASSERT_FLOAT_EQUAL(result1.y, result2.y);
}
