#include <math.h>

#include <jumpy_engine/matrix2D.h>
#include <jumpy_engine/radian.h>

#include <ctest.h>

// TODO: Add tests with a huge float value
// TODO: Add variations
// TODO: Make easier to read

auto const SQUARE_ROOT_2_OVER_2 {0.70710678118f};
auto const SQUARE_ROOT_3_OVER_2 {0.86602540378f};

CTEST(matrixRotate, const) {
    auto const matrix1 = math::Matrix2D::rotate(math::Radian{M_PI});
    ASSERT_FLOAT_EQUAL(-1, matrix1.r0c0);
    ASSERT_FLOAT_EQUAL(0, matrix1.r0c1);
    ASSERT_FLOAT_EQUAL(0, matrix1.r1c0);
    ASSERT_FLOAT_EQUAL(-1, matrix1.r1c1);
}

CTEST(matrixRotate, pi) {
    auto matrix1 = math::Matrix2D::rotate(math::Radian{M_PI});
    ASSERT_FLOAT_EQUAL(-1, matrix1.r0c0);
    ASSERT_FLOAT_EQUAL(0, matrix1.r0c1);
    ASSERT_FLOAT_EQUAL(0, matrix1.r1c0);
    ASSERT_FLOAT_EQUAL(-1, matrix1.r1c1);

    auto matrix2 = math::Matrix2D::rotate(math::Radian{M_PI / 2});
    ASSERT_FLOAT_EQUAL(0, matrix2.r0c0);
    ASSERT_FLOAT_EQUAL(-1, matrix2.r0c1);
    ASSERT_FLOAT_EQUAL(1, matrix2.r1c0);
    ASSERT_FLOAT_EQUAL(0, matrix2.r1c1);

    auto matrix3 = math::Matrix2D::rotate(math::Radian{M_PI / 3});
    ASSERT_FLOAT_EQUAL(0.5, matrix3.r0c0);
    ASSERT_FLOAT_EQUAL(-1 * SQUARE_ROOT_3_OVER_2, matrix3.r0c1);
    ASSERT_FLOAT_EQUAL(SQUARE_ROOT_3_OVER_2, matrix3.r1c0);
    ASSERT_FLOAT_EQUAL(0.5, matrix3.r1c1);

    auto matrix4 = math::Matrix2D::rotate(math::Radian{M_PI / 4});
    ASSERT_FLOAT_EQUAL(SQUARE_ROOT_2_OVER_2, matrix4.r0c0);
    ASSERT_FLOAT_EQUAL(-1 * SQUARE_ROOT_2_OVER_2, matrix4.r0c1);
    ASSERT_FLOAT_EQUAL(SQUARE_ROOT_2_OVER_2, matrix4.r1c0);
    ASSERT_FLOAT_EQUAL(SQUARE_ROOT_2_OVER_2, matrix4.r1c1);

    auto matrix5 = math::Matrix2D::rotate(math::Radian{M_PI / -3});
    ASSERT_FLOAT_EQUAL(0.5, matrix5.r0c0);
    ASSERT_FLOAT_EQUAL(SQUARE_ROOT_3_OVER_2, matrix5.r0c1);
    ASSERT_FLOAT_EQUAL(-1 * SQUARE_ROOT_3_OVER_2, matrix5.r1c0);
    ASSERT_FLOAT_EQUAL(0.5, matrix5.r1c1);

    auto matrix6 = math::Matrix2D::rotate(math::Radian{M_PI / -4});
    ASSERT_FLOAT_EQUAL(SQUARE_ROOT_2_OVER_2, matrix6.r0c0);
    ASSERT_FLOAT_EQUAL(SQUARE_ROOT_2_OVER_2, matrix6.r0c1);
    ASSERT_FLOAT_EQUAL(-1 * SQUARE_ROOT_2_OVER_2, matrix6.r1c0);
    ASSERT_FLOAT_EQUAL(SQUARE_ROOT_2_OVER_2, matrix6.r1c1);
}

CTEST(matrixRotate, zero) {
    auto matrix = math::Matrix2D::rotate(math::Radian{0.0});

    ASSERT_FLOAT_EQUAL(1, matrix.r0c0);
    ASSERT_FLOAT_EQUAL(0, matrix.r0c1);
    ASSERT_FLOAT_EQUAL(0, matrix.r1c0);
    ASSERT_FLOAT_EQUAL(1, matrix.r1c1);
}
