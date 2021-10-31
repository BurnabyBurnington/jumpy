#pragma once

#include <initializer_list>

namespace math
{
    class Radian
    {
        public:
            explicit Radian(): value(0) {};
            explicit Radian(float value): value(value) {};
            Radian(std::initializer_list<float> list): value(*list.begin()) {};

        private:
            float value;
    };

}

int another();
