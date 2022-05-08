#include <chrono>

#include <jumpy_engine/clock.h>

namespace engine
{
    void Clock::initialize()
    {
        this->timeLastFrame = std::chrono::high_resolution_clock::now();
    }

    void Clock::newFrame()
    {
        auto const now = std::chrono::high_resolution_clock::now();
        float const secondsDifference = std::chrono::duration<double>(now - this->timeLastFrame).count();

        this->secondsDifference = secondsDifference;
        this->timeLastFrame = now;
    }

    // TODO: Double-check the use of `const`, here
    float Clock::timeSinceLastFrame() const
    {
        return this->secondsDifference;
    }
}
