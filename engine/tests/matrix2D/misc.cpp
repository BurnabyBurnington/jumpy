#include <ctest.h>
#include <matrix2D.h>

CTEST(matrixBasics, default)
{
    math::Matrix2D matrix {};

    ASSERT_EQUAL(0.0f, matrix.r0c1);
    ASSERT_EQUAL(0.0f, matrix.r1c0);
    ASSERT_EQUAL(1.0f, matrix.r0c0);
    ASSERT_EQUAL(1.0f, matrix.r1c1);
}

CTEST(matrixBasics, initialization)
{
    math::Matrix2D matrix {1, 2, 3, 4};

    ASSERT_EQUAL(1.0f, matrix.r0c1);
    ASSERT_EQUAL(2.0f, matrix.r1c0);
    ASSERT_EQUAL(3.0f, matrix.r0c0);
    ASSERT_EQUAL(4.0f, matrix.r1c1);
}
