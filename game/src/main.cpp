#include <utility>

#include <QApplication>
#include <QTimer>

#include <jumpy_engine/clock.h>

#include <components/components.h>
#include <entityHandle.h>
#include <systems/playerMovement.h>
#include <systems/pointRenderer.h>
#include <utilities/playerMesh.h>
#include <window.h>
#include <world.h>

namespace {
    engine::Clock CLOCK {};
}


int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    game::World world {};
    auto mover = std::make_unique<game::systems::PlayerMovement>();
    world.addSystem(std::move(mover));
    auto renderer = std::make_unique<game::systems::PointRenderer>();
    world.addSystem(std::move(renderer));

    auto player {world.createEntity()};
    player.addComponent(game::components::Health{3, 10});
    player.addComponent(game::components::Motion{});
    player.addComponent(game::components::Transform{});
    player.addComponent(game::components::MeshPoints{game::utilities::makePlayerMesh()});
    // player.addComponent(game::components::Renderable());

    world.initialize();
    game::Window window {&world};
    window.show();

    auto runGameLoop = [&application, &world, &window]() {
        auto totalTime{0.0};
        // TODO: Check if we really need the double precision, anyway
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
