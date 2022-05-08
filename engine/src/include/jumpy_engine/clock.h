#pragma once

#include <chrono>


namespace engine
{
    class Clock
    {
        public:
            Clock() = default;
            ~Clock() = default;

            void initialize();
            void newFrame();
            float timeSinceLastFrame() const;

        private:
            // TODO: Consider changing to long long. Check if necessary, later
            float secondsDifference {-1.0f};
            std::chrono::time_point<std::chrono::high_resolution_clock> timeLastFrame {};
    };
}
