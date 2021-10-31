#pragma once


namespace math
{
    class Radian;
    class Vector3D;

    class Matrix3D {
        public:
            explicit Matrix3D() : r0c0(1), r0c1(0), r0c2(0), r1c0(0), r1c1(1), r1c2(0), r2c0(0), r2c1(0), r2c2(1) {};
            explicit Matrix3D(float r0c0, float r0c1, float r0c2, float r1c0, float r1c1, float r1c2, float r2c0, float r2c1, float r2c2) : r0c0(r0c0), r0c1(r0c1), r0c2(r0c2), r1c0(r1c0), r1c1(r1c1), r1c2(r1c2), r2c0(r2c0), r2c1(r2c1), r2c2(r2c2) {};

            ~Matrix3D() = default;

            static Matrix3D rotate_z(Radian const &angle);

            friend Vector3D operator*(Matrix3D const &left, Vector3D const &right);

            // TODO: Make the indices private, later
            // TODO: Check later if a members list produces less instructions / is faster
            float r0c0;
            float r0c1;
            float r0c2;
            float r1c0;
            float r1c1;
            float r1c2;
            float r2c0;
            float r2c1;
            float r2c2;
    };
}
