#include <math.h>

#include <ctest.h>

#include <jumpy_engine/vector2D.h>
#include <jumpy_engine/vector3D.h>
#include <jumpy_engine/matrix3D.h>


CTEST(matrixTranslate, const) {
    auto translator = math::Matrix3D::translate(math::Vector2D{4, 8});
    auto affector = math::Vector3D{-3, 8, 4};

    auto result = translator * affector;

    ASSERT_FLOAT_EQUAL(13, result.x);
    ASSERT_FLOAT_EQUAL(40, result.y);
    ASSERT_FLOAT_EQUAL(4, result.z);
}
