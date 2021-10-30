#include <ctest.h>
#include <matrix2D.h>

CTEST(matrixBasics, initialization)
{
    engine::Matrix2D matrix {};

    ASSERT_EQUAL(0.0f, matrix.r0c1);
    ASSERT_EQUAL(0.0f, matrix.r1c0);
    ASSERT_EQUAL(1.0f, matrix.r0c0);
    ASSERT_EQUAL(1.0f, matrix.r1c1);
}

