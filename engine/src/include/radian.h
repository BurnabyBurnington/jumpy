#pragma once

#include <initializer_list>

// TODO: Consider adding const for everything
namespace math
{
    class Radian
    {
        public:
            explicit Radian(): value(0) {};
            explicit Radian(float value): value(value) {};

            float get() const { return this->value; };
            float get() { return this->value; };

        private:
            float value;
    };

}

int another();
