#include <math.h>

#include <ctest.h>
#include <matrix2D.h>
#include <radian.h>

// TODO: Add tests with a huge float value
// TODO: Add variations

CTEST(matrixRotate, zero) {
    auto matrix = math::Matrix2D::rotate(math::Radian{0.0});

    ASSERT_FLOAT_EQUAL(matrix.r0c0, 1);
    ASSERT_FLOAT_EQUAL(matrix.r0c0, 1);
    ASSERT_FLOAT_EQUAL(matrix.r0c1, 0);
    ASSERT_FLOAT_EQUAL(matrix.r1c0, 0);
    ASSERT_FLOAT_EQUAL(matrix.r1c1, 1);
}

CTEST(matrixRotate, pi) {
    auto matrix = math::Matrix2D::rotate(M_PI);
    ASSERT_FLOAT_EQUAL(matrix.r0c0, 1);
    ASSERT_FLOAT_EQUAL(matrix.r0c1, 0);
    ASSERT_FLOAT_EQUAL(matrix.r1c0, 0);
    ASSERT_FLOAT_EQUAL(matrix.r1c1, 1);
}

//     auto matrix = math::Matrix2D::rotate(M_PI / 2);
//     ASSERT_FLOAT_EQUAL(matrix.r0c0, 1);
//     ASSERT_FLOAT_EQUAL(matrix.r0c1, 0);
//     ASSERT_FLOAT_EQUAL(matrix.r1c0, 0);
//     ASSERT_FLOAT_EQUAL(matrix.r1c1, 1);
//
//     auto matrix = math::Matrix2D::rotate(M_PI / 3);
//     ASSERT_FLOAT_EQUAL(matrix.r0c0, 1);
//     ASSERT_FLOAT_EQUAL(matrix.r0c1, 0);
//     ASSERT_FLOAT_EQUAL(matrix.r1c0, 0);
//     ASSERT_FLOAT_EQUAL(matrix.r1c1, 1);
//
//     auto matrix = math::Matrix2D::rotate(M_PI / 4);
//     ASSERT_FLOAT_EQUAL(matrix.r0c0, 1);
//     ASSERT_FLOAT_EQUAL(matrix.r0c1, 0);
//     ASSERT_FLOAT_EQUAL(matrix.r1c0, 0);
//     ASSERT_FLOAT_EQUAL(matrix.r1c1, 1);
//
//     auto matrix = math::Matrix2D::rotate(-M_PI / 4);
//     ASSERT_FLOAT_EQUAL(matrix.r0c0, 1);
//     ASSERT_FLOAT_EQUAL(matrix.r0c1, 0);
//     ASSERT_FLOAT_EQUAL(matrix.r1c0, 0);
//     ASSERT_FLOAT_EQUAL(matrix.r1c1, 1);
// }
//
