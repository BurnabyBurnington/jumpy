#include <ctest.h>

#include <jumpy_engine/vector2D.h>

CTEST(vectorBasics, default)
{
    math::Vector2D vector {};

    ASSERT_FLOAT_EQUAL(0, vector.x);
    ASSERT_FLOAT_EQUAL(0, vector.y);
}

CTEST(vectorBasics, initialization)
{
    math::Vector2D vector {10, -123.3};

    ASSERT_FLOAT_EQUAL(10, vector.x);
    ASSERT_FLOAT_EQUAL(-123.3, vector.y);
}
