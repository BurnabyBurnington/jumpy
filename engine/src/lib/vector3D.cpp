#include <vector3D.h>

namespace math {
    Vector3D operator+(Vector3D const &left, Vector3D const &right)
    {
        return Vector3D {left.x + right.x, left.y + right.y, left.z + right.z};
    }

    // TODO: Make sure to convert `float` into `T` once this is a template class
    // TODO: Shouldn't this return a reference?
    Vector3D operator+(Vector3D const &left, float scalar)
    {
        return Vector3D {left.x + scalar, left.y + scalar, left.z + scalar};
    }

    Vector3D operator+(float scalar, Vector3D const &right)
    {
        return Vector3D {right.x + scalar, right.y + scalar, right.z + scalar};
    }

    // TODO: Is reflexive addition possible in C++ if the types differ?
    // Double-check this. Do the same for multiplication, too
    //
    Vector3D operator*(Vector3D const &left, Vector3D const &right)
    {
        return Vector3D {left.x * right.x, left.y * right.y, left.z * right.z};
    }

    // TODO: Make sure to convert `float` into `T` once this is a template class
    // TODO: Shouldn't this return a reference?
    Vector3D operator*(Vector3D const &left, float scalar)
    {
        return Vector3D {left.x * scalar, left.y * scalar, left.z * scalar};
    }

    Vector3D operator*(float scalar, Vector3D const &right)
    {
        return Vector3D {right.x * scalar, right.y * scalar, right.z * scalar};
    }
}
