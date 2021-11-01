#include <math.h>

#include <ctest.h>
#include <vector2D.h>
#include <matrix3D.h>


CTEST(matrixTranslate, const) {
    auto translator = math::Matrix3D::translate(Vector2D{4, 8});
    auto affector = Vector3D{-3, 8, 1};

    auto result = translator * affector;

    ASSERT_FLOAT_EQ(1, result.x);
    ASSERT_FLOAT_EQ(16, result.x);
    ASSERT_FLOAT_EQ(0, result.x);
}
