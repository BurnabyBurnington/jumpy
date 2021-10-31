#pragma once

namespace math {
    // TODO: Make this into a template, later
    // TODO: Const-ify everything
    class Vector2D
    {
        public:
            Vector2D() : x(0.0f), y(0.0f) {};
            Vector2D(float x, float y) : x(x), y(y) {};
            ~Vector2D() = default;

            float x;
            float y;

            // TODO: Make these inline?
            friend Vector2D operator+(Vector2D const &left, Vector2D const &right);
            friend Vector2D operator+(Vector2D const &left, float scalar);
            friend Vector2D operator*(Vector2D const &left, Vector2D const &right);
            friend Vector2D operator*(Vector2D const &left, float scalar);

            Vector2D& operator+=(Vector2D const &right)
            {
                // TODO: Maybe I can somehow reuse operator+ or vice versa?
                this->x += right.x;
                this->y += right.y;

                return *this;
            }

            // TODO: Make sure to convert `float` into `T` once this is a template class
            // TODO: Shouldn't this return a reference?
            Vector2D& operator+=(float scalar)
            {
                this->x += scalar;
                this->y += scalar;

                return *this;
            }

            Vector2D& operator-=(Vector2D const &right)
            {
                // TODO: Maybe I can somehow reuse operator+ or vice versa?
                this->x -= right.x;
                this->y -= right.y;

                return *this;
            }

            Vector2D& operator-=(float scalar)
            {
                this->x -= scalar;
                this->y -= scalar;

                return *this;
            }
    };

    // template<class T>
    // class Vector2D
    // {
    //     public:
    //         Vector2D(T x, T y) : x(x), y(y) {};
    //         T x;
    //         T y;
    //
    //         friend Vector2D const operator+(Vector2D const &left, Vector2D const &right);
    //         friend Vector2D const operator*(Vector2D const &left, Vector2D const &right);
    // };
    //
    // template<typename T>
    // Vector2D const operator+(Vector2D const &left, Vector2D const &right)
    // {
    //     return Vector2D {left.x + right.x, left.y + right.y};
    // }
    //
    // template<typename T>
    // Vector2D const operator*(Vector2D const &left, Vector2D const &right)
    // {
    //     return Vector2D {left.x * right.x, left.y * right.y};
    // }
}
