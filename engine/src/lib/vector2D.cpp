#include <vector2D.h>

namespace math {
    Vector2D operator+(Vector2D const &left, Vector2D const &right)
    {
        return Vector2D {left.x + right.x, left.y + right.y};
    }

    // TODO: Make sure to convert `float` into `T` once this is a template class
    // TODO: Shouldn't this return a reference?
    Vector2D operator+(Vector2D const &left, float scalar)
    {
        return Vector2D {left.x + scalar, left.y + scalar};
    }

    // TODO: Is reflexive addition possible in C++ if the types differ?
    // Double-check this. Do the same for multiplication, too
    //
    Vector2D operator*(Vector2D const &left, Vector2D const &right)
    {
        return Vector2D {left.x * right.x, left.y * right.y};
    }

    // TODO: Make sure to convert `float` into `T` once this is a template class
    // TODO: Shouldn't this return a reference?
    Vector2D operator*(Vector2D const &left, float scalar)
    {
        return Vector2D {left.x * scalar, left.y * scalar};
    }
}
