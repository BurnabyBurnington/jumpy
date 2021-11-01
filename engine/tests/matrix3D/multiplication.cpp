#include <cassert>
#include <ctest.h>
#include <matrix3D.h>
#include <vector3D.h>

// TODO: Add tests with a huge float value
// TODO: Add tests to ensure the + operator can be chained repeatedly

CTEST(matrixMultiplication, matrix) {
    auto matrix1 = math::Matrix3D {
        2, -3, 4,
        -5, 6, 7,
        8, -12, 10,
    };

    auto result = matrix1 * matrix1;

    ASSERT_EQUAL(51, result.r0c0);
    ASSERT_EQUAL(-72, result.r0c1);
    ASSERT_EQUAL(27, result.r0c2);
    ASSERT_EQUAL(16, result.r1c0);
    ASSERT_EQUAL(-33, result.r1c1);
    ASSERT_EQUAL(92, result.r1c2);
    ASSERT_EQUAL(156, result.r2c0);
    ASSERT_EQUAL(-216, result.r2c1);
    ASSERT_EQUAL(48, result.r2c2);
}

CTEST(matrixMultiplication, vector) {
    math::Matrix3D matrix{
        2, -3, 4,
        -5, 6, 7,
        8, -12, 10,
    };
    math::Vector3D vector{3, 9, -4};

    auto result = matrix * vector;

    ASSERT_EQUAL(-37, result.x);
    ASSERT_EQUAL(11, result.y);
    ASSERT_EQUAL(-124, result.z);
}
