#include <chrono>
#include <clock.h>

namespace engine
{
    void Clock::initialize()
    {
        this->timeLastFrame = std::chrono::high_resolution_clock::now();
    }

    void Clock::newFrame()
    {
        auto now = std::chrono::high_resolution_clock::now();
        float secondsDifference = std::chrono::duration<double>(now - this->timeLastFrame).count();

        this->secondsDifference = secondsDifference;
        this->timeLastFrame = now;
    }

    // TODO: Double-check the use of `const`, here
    float Clock::timeSinceLastFrame() const
    {
        return this->secondsDifference;
    }
}
