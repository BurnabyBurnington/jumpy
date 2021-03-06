#include <QApplication>
#include <QTimer>

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

    auto runGameLoop = [&application, &window]() {
        auto totalTime{0.0};
        auto const delta{0.02};

        CLOCK.initialize();
        auto accumulator{0.0};

        while (!window.needsQuit())
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
    };

    QTimer::singleShot(0, runGameLoop);

    return application.exec();
}
