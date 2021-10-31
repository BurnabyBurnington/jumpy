#include <cassert>
#include <ctest.h>
#include <vector3D.h>

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
