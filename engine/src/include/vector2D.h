#pragma once

namespace engine {
    template<class T>
    class Vector2D
    {
        public:
            Vector2D(T x, T y) : x(x), y(y) {};
            T x;
            T y;

            friend Vector2D const operator+(Vector2D const &left, Vector2D const &right) {};
            friend Vector2D const operator*(Vector2D const &left, Vector2D const &right) {};
    };

    template<typename T>
    Vector2D const Vector2D::operator+(Vector2D const &left, Vector2D const &right)
    {
        return Vector2D {left.x + right.x, left.y + right.y};
    }

    template<typename T>
    Vector2D const Vector2D::operator*(Vector2D const &left, Vector2D const &right)
    {
        return Vector2D {left.x * right.x, left.y * right.y};
    }
}

