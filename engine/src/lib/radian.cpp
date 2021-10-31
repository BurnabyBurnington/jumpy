#include <string>
#include <iostream>
#include <radian.h>

namespace {
    std::string footest(math::Radian const &blah)
    {
        return "something";
    }
}

int another()
{
    std::cout << footest({110.0}) << std::endl;

    return 11;
}
