#include <cassert>
#include <chrono>
#include <thread>

#include <jumpy_engine/clock.h>

#include <ctest.h>  // TODO: Make this into a common library, later

void sleepSeconds(float seconds){
    auto duration = std::chrono::duration<double>(seconds);
    std::this_thread::sleep_for(duration);
};

// TODO: Add tests with a huge int value
// TODO: Add tests to ensure the + operator can be chained repeatedly

CTEST(clock, initialization) {
    engine::Clock clock {};

    clock.initialize();
}

CTEST(clock, timeMeasuring) {
    engine::Clock clock {};

    clock.initialize();
    ASSERT_EQUAL(-1.0f, clock.timeSinceLastFrame());

    sleepSeconds(1.0f);
    clock.newFrame();
    auto last = clock.timeSinceLastFrame();
    ASSERT_TRUE(0.9f < last);
    ASSERT_TRUE(last < 1.1f);

    sleepSeconds(0.5f);
    clock.newFrame();
    last = clock.timeSinceLastFrame();
    ASSERT_TRUE(0.4f < last);
    ASSERT_TRUE(last < 0.6f);
}

CTEST(clock, timeRandom) {
    engine::Clock clock {};

    clock.initialize();

    const int count = 10 + rand() % 10;
    // `threshold` is an arbitrary leeway value. Make value smaller for more
    // precise tests.
    //
    const float threshold = 0.001f;

    for (int index = 0; index < count; ++index)
    {
        int milliseconds = rand() % 10000;
        float seconds = milliseconds / 1000.0f;
        clock.newFrame();
        sleepSeconds(seconds);
        clock.newFrame();
        float elapsed = clock.timeSinceLastFrame();
        ASSERT_TRUE(seconds - threshold < elapsed);
        ASSERT_TRUE(elapsed < seconds + threshold);
    }

    ASSERT_EQUAL(0, clock.timeSinceLastFrame());

    sleepSeconds(1.0f);
    clock.newFrame();
    auto last = clock.timeSinceLastFrame();
    ASSERT_TRUE(0.9f < last);
    ASSERT_TRUE(last < 1.1f);

    sleepSeconds(0.5f);
    clock.newFrame();
    last = clock.timeSinceLastFrame();
    ASSERT_TRUE(0.4f < last);
    ASSERT_TRUE(last < 0.6f);
}
