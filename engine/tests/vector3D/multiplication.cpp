#include <cassert>
#include <ctest.h>

#include <jumpy_engine/vector3D.h>

// TODO: Add tests with a huge float value
// TODO: Add tests to ensure the + operator can be chained repeatedly

CTEST(vectorMultiplicationConst, scalar) {
    auto const first = math::Vector3D {10, 12, -2};

    auto const vector1 = first * 2;
    ASSERT_FLOAT_EQUAL(20, vector1.x);
    ASSERT_FLOAT_EQUAL(24, vector1.y);
    ASSERT_FLOAT_EQUAL(-4, vector1.z);

    auto const vector2 = first * -2;
    ASSERT_FLOAT_EQUAL(-20, vector2.x);
    ASSERT_FLOAT_EQUAL(-24, vector2.y);
    ASSERT_FLOAT_EQUAL(4, vector2.z);
}

CTEST(vectorMultiplicationConst, scalarReflexivity) {
    auto const first = math::Vector3D {10, 12, -3};
    auto const vector3 = first * -100;
    auto const vector4 = -100 * first;

    ASSERT_FLOAT_EQUAL(-1000, vector3.x);
    ASSERT_FLOAT_EQUAL(-1200, vector3.y);
    ASSERT_FLOAT_EQUAL(300, vector3.z);
    ASSERT_FLOAT_EQUAL(-1000, vector4.x);
    ASSERT_FLOAT_EQUAL(-1200, vector4.y);
    ASSERT_FLOAT_EQUAL(300, vector4.z);
    ASSERT_FLOAT_EQUAL(vector3.x, vector4.x);
    ASSERT_FLOAT_EQUAL(vector3.y, vector4.y);
    ASSERT_FLOAT_EQUAL(vector3.z, vector4.z);
}

CTEST(vectorMultiplicationConst, vector) {
    auto const first = math::Vector3D {10, 12, -10};
    auto const second = math::Vector3D {-2, 100, -3};

    auto const vector1 = first * second;

    ASSERT_FLOAT_EQUAL(-20, vector1.x);
    ASSERT_FLOAT_EQUAL(1200, vector1.y);
    ASSERT_FLOAT_EQUAL(30, vector1.z);

    auto const vector2 = second * first;

    ASSERT_FLOAT_EQUAL(-20, vector2.x);
    ASSERT_FLOAT_EQUAL(1200, vector2.y);
    ASSERT_FLOAT_EQUAL(30, vector2.z);
}

CTEST(additionConstOperators, vectorReflexivity) {
    auto const first = math::Vector3D {10, 12, -30};
    auto const second = math::Vector3D {25, -35, -20};
    auto const result1 = first * second;
    auto const result2 = second * first;

    ASSERT_FLOAT_EQUAL(250, result1.x);
    ASSERT_FLOAT_EQUAL(-420, result1.y);
    ASSERT_FLOAT_EQUAL(600, result1.z);
    ASSERT_FLOAT_EQUAL(250, result2.x);
    ASSERT_FLOAT_EQUAL(-420, result2.y);
    ASSERT_FLOAT_EQUAL(600, result2.z);
    ASSERT_FLOAT_EQUAL(result1.x, result2.x);
    ASSERT_FLOAT_EQUAL(result1.y, result2.y);
    ASSERT_FLOAT_EQUAL(result1.z, result2.z);
}

CTEST(vectorMultiplication, scalar) {
    auto first = math::Vector3D {10, 12, -2};

    auto vector1 = first * 2;
    ASSERT_FLOAT_EQUAL(20, vector1.x);
    ASSERT_FLOAT_EQUAL(24, vector1.y);
    ASSERT_FLOAT_EQUAL(-4, vector1.z);

    auto vector2 = first * -2;
    ASSERT_FLOAT_EQUAL(-20, vector2.x);
    ASSERT_FLOAT_EQUAL(-24, vector2.y);
    ASSERT_FLOAT_EQUAL(4, vector2.z);
}

CTEST(vectorMultiplication, scalarReflexivity) {
    auto first = math::Vector3D {10, 12, -3};
    auto vector3 = first * -100;
    auto vector4 = -100 * first;

    ASSERT_FLOAT_EQUAL(-1000, vector3.x);
    ASSERT_FLOAT_EQUAL(-1200, vector3.y);
    ASSERT_FLOAT_EQUAL(300, vector3.z);
    ASSERT_FLOAT_EQUAL(-1000, vector4.x);
    ASSERT_FLOAT_EQUAL(-1200, vector4.y);
    ASSERT_FLOAT_EQUAL(300, vector4.z);
    ASSERT_FLOAT_EQUAL(vector3.x, vector4.x);
    ASSERT_FLOAT_EQUAL(vector3.y, vector4.y);
    ASSERT_FLOAT_EQUAL(vector3.z, vector4.z);
}

CTEST(vectorMultiplication, vector) {
    auto first = math::Vector3D {10, 12, -10};
    auto second = math::Vector3D {-2, 100, -3};

    auto vector1 = first * second;

    ASSERT_FLOAT_EQUAL(-20, vector1.x);
    ASSERT_FLOAT_EQUAL(1200, vector1.y);
    ASSERT_FLOAT_EQUAL(30, vector1.z);

    auto vector2 = second * first;

    ASSERT_FLOAT_EQUAL(-20, vector2.x);
    ASSERT_FLOAT_EQUAL(1200, vector2.y);
    ASSERT_FLOAT_EQUAL(30, vector2.z);
}

CTEST(additionOperators, vectorReflexivity) {
    auto first = math::Vector3D {10, 12, -30};
    auto second = math::Vector3D {25, -35, -20};
    auto result1 = first * second;
    auto result2 = second * first;

    ASSERT_FLOAT_EQUAL(250, result1.x);
    ASSERT_FLOAT_EQUAL(-420, result1.y);
    ASSERT_FLOAT_EQUAL(600, result1.z);
    ASSERT_FLOAT_EQUAL(250, result2.x);
    ASSERT_FLOAT_EQUAL(-420, result2.y);
    ASSERT_FLOAT_EQUAL(600, result2.z);
    ASSERT_FLOAT_EQUAL(result1.x, result2.x);
    ASSERT_FLOAT_EQUAL(result1.y, result2.y);
    ASSERT_FLOAT_EQUAL(result1.z, result2.z);
}
