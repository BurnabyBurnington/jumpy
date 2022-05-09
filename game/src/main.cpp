#include <utility>

#include <QApplication>
#include <QTimer>

#include <jumpy_engine/clock.h>

#include <components.h>
#include <entityHandle.h>
#include <systems/joystick.h>
#include <window.h>
#include <world.h>

namespace {
    engine::Clock CLOCK {};
}


int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    game::World world {};
    auto player {world.createEntity()};
    // TODO: Replace with {}s, if able
    player.addComponent(game::components::Health(3, 10));
    player.addComponent(game::components::Motion());
    player.addComponent(game::components::Transform());

    auto joystick = std::make_unique<game::systems::Joystick>();
    world.addSystem(std::move(joystick));

    world.initialize();
    game::Window window {};
    window.show();

    auto runGameLoop = [&application, &world, &window]() {
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
                if (window.allowUserInput())
                {
                    world.update(delta);
                }

                accumulator -= delta;
                totalTime += delta;
            }

            window.updateGL();
        }
    };

    QTimer::singleShot(0, runGameLoop);

    return application.exec();
}
