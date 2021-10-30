#pragma once

namespace engine
{
    class Vector2D;

    class Matrix2D {
        public:
            explicit Matrix2D() : r0c0(1), r0c1(0), r1c0(0), r1c1(1) {};
            explicit Matrix2D(float r0c0, float r0c1, float r1c0, float r1c1) : r0c0(r0c0), r0c1(r0c1), r1c0(r1c0), r1c1(r1c1) {};
            ~Matrix2D() = default;

            // TODO: Make the indices private, later
            // TODO: Check later if a members list produces less instructions / is faster
            float r0c0;
            float r0c1;
            float r1c0;
            float r1c1;
    };
}
