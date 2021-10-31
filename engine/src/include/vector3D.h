#pragma once

namespace math {
    // TODO: Make this into a template, later
    // TODO: Const-ify everything
    class Vector3D
    {
        public:
            Vector3D() : x(0.0f), y(0.0f), z(0.0f) {};
            Vector3D(float x, float y, float z) : x(x), y(y), z(z) {};
            ~Vector3D() = default;

            float x;
            float y;
            float z;

            // TODO: Make these inline?
            friend Vector3D operator*(Vector3D const &left, Vector3D const &right);
            friend Vector3D operator*(Vector3D const &left, float scalar);
            friend Vector3D operator*(float scalar, Vector3D const &right);
            friend Vector3D operator+(Vector3D const &left, Vector3D const &right);
            friend Vector3D operator+(Vector3D const &left, float scalar);
            friend Vector3D operator+(float scalar, Vector3D const &right);

            Vector3D& operator+=(Vector3D const &right)
            {
                // TODO: Maybe I can somehow reuse operator+ or vice versa?
                this->x += right.x;
                this->y += right.y;
                this->z += right.z;

                return *this;
            }

            // TODO: Make sure to convert `float` into `T` once this is a template class
            // TODO: Shouldn't this return a reference?
            Vector3D& operator+=(float scalar)
            {
                this->x += scalar;
                this->y += scalar;
                this->z += scalar;

                return *this;
            }

            Vector3D& operator-=(Vector3D const &right)
            {
                // TODO: Maybe I can somehow reuse operator+ or vice versa?
                this->x -= right.x;
                this->y -= right.y;
                this->z -= right.y;

                return *this;
            }

            Vector3D& operator-=(float scalar)
            {
                this->x -= scalar;
                this->y -= scalar;
                this->z -= scalar;

                return *this;
            }
    };
}
