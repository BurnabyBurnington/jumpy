#include <cassert>
#include <ctest.h>
#include <matrix3D.h>
#include <vector3D.h>

// TODO: Add tests with a huge float value
// TODO: Add tests to ensure the + operator can be chained repeatedly

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
