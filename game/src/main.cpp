#include <QApplication>
#include <QDebug>

#include <clock.h>

#include <window.h>

namespace {
    engine::Clock CLOCK {};
}

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    game::Window window {};
    window.show();

    auto totalTime{0.0};
    auto const delta{0.02};
    auto quit{false};

    CLOCK.initialize();
    auto accumulator{0.0};

    while (!quit)
    {
        if (application.hasPendingEvents())
        {
            application.processEvents();
        }

        CLOCK.newFrame();
        auto const frameTime {CLOCK.timeSinceLastFrame()};

        accumulator += frameTime;

        while (accumulator >= delta)
        {
            window.simulate(delta);
            accumulator -= delta;
            totalTime += delta;
        }

        window.updateGL();
    }

    return application.exec();
}
