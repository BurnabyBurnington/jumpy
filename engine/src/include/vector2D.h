#pragma once

namespace engine {
    // TODO: Make this into a template, later
    // TODO: Const-ify everything
    class Vector2D
    {
        public:
            Vector2D(int x, int y) : x(x), y(y) {};

            int x;
            int y;

            friend Vector2D operator+(Vector2D const &left, Vector2D const &right);
            friend Vector2D operator+(Vector2D const &left, float scalar);
            // TODO: Add this
            // friend Vector2D operator*(Vector2D const &left, Vector2D const &right);
    };

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

    // TODO: Add this
    // Vector2D operator*(Vector2D const &left, Vector2D const &right)
    // {
    //     return Vector2D {left.x * right.x, left.y * right.y};
    // }

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

