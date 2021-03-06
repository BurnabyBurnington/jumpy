#include <cmath>  // cos, sin

#include <radian.h>
#include <matrix3D.h>
#include <vector2D.h>
#include <vector3D.h>

namespace math
{
    Matrix3D Matrix3D::rotateZ(Radian const &angle) {
        auto const value = angle.get();
        auto const cos = std::cos(value);
        auto const sin = std::sin(value);

        return Matrix3D {
            cos, -1 * sin, 0,
            sin, cos, 0,
            0, 0, 1
        };
    }

    Matrix3D Matrix3D::translate(Vector2D const &vector)
    {
        return Matrix3D {
            1, 0, vector.x,
            0, 1, vector.y,
            0, 0, 1
        };
    }

    Matrix3D operator*(Matrix3D const &left, Matrix3D const &right)
    {
        // TODO: Consider changing to an unrolled loop
        return Matrix3D {
            (left.r0c0 * right.r0c0) + (left.r0c1 * right.r1c0) + (left.r0c2 * right.r2c0),
            (left.r0c0 * right.r0c1) + (left.r0c1 * right.r1c1) + (left.r0c2 * right.r2c1),
            (left.r0c0 * right.r0c2) + (left.r0c1 * right.r1c2) + (left.r0c2 * right.r2c2),

            (left.r1c0 * right.r0c0) + (left.r1c1 * right.r1c0) + (left.r1c2 * right.r2c0),
            (left.r1c0 * right.r0c1) + (left.r1c1 * right.r1c1) + (left.r1c2 * right.r2c1),
            (left.r1c0 * right.r0c2) + (left.r1c1 * right.r1c2) + (left.r1c2 * right.r2c2),

            (left.r2c0 * right.r0c0) + (left.r2c1 * right.r1c0) + (left.r2c2 * right.r2c0),
            (left.r2c0 * right.r0c1) + (left.r2c1 * right.r1c1) + (left.r2c2 * right.r2c1),
            (left.r2c0 * right.r0c2) + (left.r2c1 * right.r1c2) + (left.r2c2 * right.r2c2)
        };
    }

    Vector3D operator*(Matrix3D const &left, Vector3D const &right)
    {
        return {
            (left.r0c0 * right.x) + (left.r0c1 * right.y) + (left.r0c2 * right.z),
            (left.r1c0 * right.x) + (left.r1c1 * right.y) + (left.r1c2 * right.z),
            (left.r2c0 * right.x) + (left.r2c1 * right.y) + (left.r2c2 * right.z)
        };
    }
}

