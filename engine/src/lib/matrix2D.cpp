#include <matrix2D.h>
#include <vector2D.h>

namespace math
{
    Vector2D operator*(Matrix2D const &left, Vector2D const &right)
    {
        return {
            left.r0c0 * right.x + left.r0c1 * right.y,
            left.r1c0 * right.x + left.r1c1 * right.y
        };
    }
}
