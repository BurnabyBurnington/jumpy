#include <ctest.h>

#include <jumpy_engine/vector3D.h>

CTEST(vectorBasics, defaults)
{
    math::Vector3D vector {};

    ASSERT_FLOAT_EQUAL(0, vector.x);
    ASSERT_FLOAT_EQUAL(0, vector.y);
    ASSERT_FLOAT_EQUAL(0, vector.z);
}

CTEST(vectorBasics, initialization)
{
    math::Vector3D vector {-10, 10000, -40};

    ASSERT_FLOAT_EQUAL(-10, vector.x);
    ASSERT_FLOAT_EQUAL(10000, vector.y);
    ASSERT_FLOAT_EQUAL(-40, vector.z);
}
