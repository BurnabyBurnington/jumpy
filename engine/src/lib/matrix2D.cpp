#include <cmath>  // cos, sin

#include <jumpy_engine/radian.h>
#include <jumpy_engine/matrix2D.h>
#include <jumpy_engine/vector2D.h>

namespace math
{
    Matrix2D Matrix2D::rotate(Radian const &angle) {
        auto const value = angle.get();
        auto const cos = std::cos(value);
        auto const sin = std::sin(value);

        return Matrix2D {
            cos, -1 * sin,
            sin, cos
        };
    }

    Vector2D operator*(Matrix2D const &left, Vector2D const &right)
    {
        return {
            left.r0c0 * right.x + left.r0c1 * right.y,
            left.r1c0 * right.x + left.r1c1 * right.y
        };
    }
}
