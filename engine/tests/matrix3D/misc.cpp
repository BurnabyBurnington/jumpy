#include <ctest.h>
#include <matrix3D.h>

CTEST(matrixBasics, default)
{
    math::Matrix3D matrix {};

    ASSERT_EQUAL(1.0f, matrix.r0c0);
    ASSERT_EQUAL(0.0f, matrix.r0c1);
    ASSERT_EQUAL(0.0f, matrix.r0c2);
    ASSERT_EQUAL(0.0f, matrix.r1c0);
    ASSERT_EQUAL(1.0f, matrix.r1c1);
    ASSERT_EQUAL(0.0f, matrix.r1c2);
    ASSERT_EQUAL(0.0f, matrix.r2c0);
    ASSERT_EQUAL(0.0f, matrix.r2c1);
    ASSERT_EQUAL(1.0f, matrix.r2c2);
}

CTEST(matrixBasics, initialization)
{
    math::Matrix3D matrix {};

    ASSERT_EQUAL(0.0f, matrix.r0c1);
    ASSERT_EQUAL(0.0f, matrix.r1c0);
    ASSERT_EQUAL(1.0f, matrix.r0c0);
    ASSERT_EQUAL(1.0f, matrix.r1c1);
}
