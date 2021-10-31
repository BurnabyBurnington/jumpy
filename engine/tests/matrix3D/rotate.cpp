#include <math.h>

#include <ctest.h>
#include <matrix3D.h>
#include <radian.h>

// TODO: Add tests with a huge float value
// TODO: Add variations
// TODO: Make easier to read

auto const SQUARE_ROOT_2_OVER_2 {0.70710678118f};
auto const SQUARE_ROOT_3_OVER_2 {0.86602540378f};

CTEST(matrixRotate, const) {
    auto const matrix1 = math::Matrix3D::rotate_z(math::Radian{M_PI});
    ASSERT_FLOAT_EQUAL(-1, matrix1.r0c0);
    ASSERT_FLOAT_EQUAL(0, matrix1.r0c1);
    ASSERT_FLOAT_EQUAL(0, matrix1.r0c2);
    ASSERT_FLOAT_EQUAL(0, matrix1.r1c0);
    ASSERT_FLOAT_EQUAL(-1, matrix1.r1c1);
    ASSERT_FLOAT_EQUAL(0, matrix1.r1c2);
    ASSERT_FLOAT_EQUAL(0, matrix1.r2c0);
    ASSERT_FLOAT_EQUAL(0, matrix1.r2c1);
    ASSERT_FLOAT_EQUAL(1, matrix1.r2c2);
}

CTEST(matrixRotate, pi) {
    auto matrix1 = math::Matrix3D::rotate_z(math::Radian{M_PI});
    ASSERT_FLOAT_EQUAL(-1, matrix1.r0c0);
    ASSERT_FLOAT_EQUAL(0, matrix1.r0c1);
    ASSERT_FLOAT_EQUAL(0, matrix1.r0c2);
    ASSERT_FLOAT_EQUAL(0, matrix1.r1c0);
    ASSERT_FLOAT_EQUAL(-1, matrix1.r1c1);
    ASSERT_FLOAT_EQUAL(0, matrix1.r1c2);
    ASSERT_FLOAT_EQUAL(0, matrix1.r2c0);
    ASSERT_FLOAT_EQUAL(0, matrix1.r2c1);
    ASSERT_FLOAT_EQUAL(1, matrix1.r2c2);

    auto matrix2 = math::Matrix3D::rotate_z(math::Radian{M_PI / 2});
    ASSERT_FLOAT_EQUAL(0, matrix2.r0c0);
    ASSERT_FLOAT_EQUAL(-1, matrix2.r0c1);
    ASSERT_FLOAT_EQUAL(0, matrix2.r0c2);
    ASSERT_FLOAT_EQUAL(1, matrix2.r1c0);
    ASSERT_FLOAT_EQUAL(0, matrix2.r1c1);
    ASSERT_FLOAT_EQUAL(0, matrix2.r1c2);
    ASSERT_FLOAT_EQUAL(0, matrix2.r2c0);
    ASSERT_FLOAT_EQUAL(0, matrix2.r2c1);
    ASSERT_FLOAT_EQUAL(1, matrix2.r2c2);

    auto matrix3 = math::Matrix3D::rotate_z(math::Radian{M_PI / 3});
    ASSERT_FLOAT_EQUAL(0.5, matrix3.r0c0);
    ASSERT_FLOAT_EQUAL(-1 * SQUARE_ROOT_3_OVER_2, matrix3.r0c1);
    ASSERT_FLOAT_EQUAL(0, matrix3.r0c2);
    ASSERT_FLOAT_EQUAL(SQUARE_ROOT_3_OVER_2, matrix3.r1c0);
    ASSERT_FLOAT_EQUAL(0.5, matrix3.r1c1);
    ASSERT_FLOAT_EQUAL(0, matrix3.r1c2);
    ASSERT_FLOAT_EQUAL(0, matrix3.r2c0);
    ASSERT_FLOAT_EQUAL(0, matrix3.r2c1);
    ASSERT_FLOAT_EQUAL(1, matrix3.r2c2);

    auto matrix4 = math::Matrix3D::rotate_z(math::Radian{M_PI / 4});
    ASSERT_FLOAT_EQUAL(SQUARE_ROOT_2_OVER_2, matrix4.r0c0);
    ASSERT_FLOAT_EQUAL(-1 * SQUARE_ROOT_2_OVER_2, matrix4.r0c1);
    ASSERT_FLOAT_EQUAL(0, matrix4.r0c2);
    ASSERT_FLOAT_EQUAL(SQUARE_ROOT_2_OVER_2, matrix4.r1c0);
    ASSERT_FLOAT_EQUAL(SQUARE_ROOT_2_OVER_2, matrix4.r1c1);
    ASSERT_FLOAT_EQUAL(0, matrix4.r1c2);
    ASSERT_FLOAT_EQUAL(0, matrix4.r2c0);
    ASSERT_FLOAT_EQUAL(0, matrix4.r2c1);
    ASSERT_FLOAT_EQUAL(1, matrix4.r2c2);

    auto matrix5 = math::Matrix3D::rotate_z(math::Radian{M_PI / -3});
    ASSERT_FLOAT_EQUAL(0.5, matrix5.r0c0);
    ASSERT_FLOAT_EQUAL(SQUARE_ROOT_3_OVER_2, matrix5.r0c1);
    ASSERT_FLOAT_EQUAL(0, matrix5.r0c2);
    ASSERT_FLOAT_EQUAL(-1 * SQUARE_ROOT_3_OVER_2, matrix5.r1c0);
    ASSERT_FLOAT_EQUAL(0.5, matrix5.r1c1);
    ASSERT_FLOAT_EQUAL(0, matrix5.r1c2);
    ASSERT_FLOAT_EQUAL(0, matrix5.r2c0);
    ASSERT_FLOAT_EQUAL(0, matrix5.r2c1);
    ASSERT_FLOAT_EQUAL(1, matrix5.r2c2);

    auto matrix6 = math::Matrix3D::rotate_z(math::Radian{M_PI / -4});
    ASSERT_FLOAT_EQUAL(SQUARE_ROOT_2_OVER_2, matrix6.r0c0);
    ASSERT_FLOAT_EQUAL(SQUARE_ROOT_2_OVER_2, matrix6.r0c1);
    ASSERT_FLOAT_EQUAL(0, matrix6.r0c2);
    ASSERT_FLOAT_EQUAL(-1 * SQUARE_ROOT_2_OVER_2, matrix6.r1c0);
    ASSERT_FLOAT_EQUAL(SQUARE_ROOT_2_OVER_2, matrix6.r1c1);
    ASSERT_FLOAT_EQUAL(0, matrix6.r1c2);
    ASSERT_FLOAT_EQUAL(0, matrix6.r2c0);
    ASSERT_FLOAT_EQUAL(0, matrix6.r2c1);
    ASSERT_FLOAT_EQUAL(1, matrix6.r2c2);
}

CTEST(matrixRotate, zero) {
    auto matrix1 = math::Matrix3D::rotate_z(math::Radian{0.0});
    auto matrix2 = math::Matrix3D{};

    ASSERT_EQUAL(1.0f, matrix1.r0c0);
    ASSERT_EQUAL(0.0f, matrix1.r0c1);
    ASSERT_EQUAL(0.0f, matrix1.r0c2);
    ASSERT_EQUAL(0.0f, matrix1.r1c0);
    ASSERT_EQUAL(1.0f, matrix1.r1c1);
    ASSERT_EQUAL(0.0f, matrix1.r1c2);
    ASSERT_EQUAL(0.0f, matrix1.r2c0);
    ASSERT_EQUAL(0.0f, matrix1.r2c1);
    ASSERT_EQUAL(1.0f, matrix1.r2c2);

    ASSERT_EQUAL(1.0f, matrix2.r0c0);
    ASSERT_EQUAL(0.0f, matrix2.r0c1);
    ASSERT_EQUAL(0.0f, matrix2.r0c2);
    ASSERT_EQUAL(0.0f, matrix2.r1c0);
    ASSERT_EQUAL(1.0f, matrix2.r1c1);
    ASSERT_EQUAL(0.0f, matrix2.r1c2);
    ASSERT_EQUAL(0.0f, matrix2.r2c0);
    ASSERT_EQUAL(0.0f, matrix2.r2c1);
    ASSERT_EQUAL(1.0f, matrix2.r2c2);

    ASSERT_EQUAL(matrix1.r0c0, matrix2.r0c0);
    ASSERT_EQUAL(matrix1.r0c1, matrix2.r0c1);
    ASSERT_EQUAL(matrix1.r0c2, matrix2.r0c2);
    ASSERT_EQUAL(matrix1.r1c0, matrix2.r1c0);
    ASSERT_EQUAL(matrix1.r1c1, matrix2.r1c1);
    ASSERT_EQUAL(matrix1.r1c2, matrix2.r1c2);
    ASSERT_EQUAL(matrix1.r2c0, matrix2.r2c0);
    ASSERT_EQUAL(matrix1.r2c1, matrix2.r2c1);
    ASSERT_EQUAL(matrix1.r2c2, matrix2.r2c2);
}
