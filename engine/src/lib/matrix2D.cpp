#include <matrix2D.h>
#include <vector2D.h>

namespace engine
{
    Vector2D operator*(Matrix2D const &left, Vector2D const &right)
    {
        return {left.r0c0 * right.x, left.r1c0 * right.y};
    }
}