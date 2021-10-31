#include <ctest.h>
#include <vector2D.h>

CTEST(vectorBasics, default)
{
    math::Vector2D vector {};

    ASSERT_EQUAL(0, vector.x);
    ASSERT_EQUAL(0, vector.y);
}

CTEST(vectorBasics, initialization)
{
    math::Vector2D vector {10, -123.3};

    ASSERT_EQUAL(10, vector.x);
    ASSERT_EQUAL(-123.3, vector.y);
}
