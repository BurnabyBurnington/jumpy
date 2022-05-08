#include <QApplication>
#include <QTimer>

#include <jumpy_engine/clock.h>

#include <components.h>
#include <entityHandle.h>
#include <window.h>
#include <world.h>

namespace {
    engine::Clock CLOCK {};
}

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    game::World world {};
    auto player = world.createEntity();
    auto health = player.addComponent(new game::components::Health{});
    health.heal(10);

    // std::cout << "Got Health: " health.get() << '\n';
    // game::EntityManager entityManager {};
    // auto player = entityManager.create();
    //
    // game::components::Health health;
    // health.current = 10;
    // health.max = 10;
    //
    // healthManager.addComponent(player, health);
    //
    // Window window {};
    //
    // window.show();
    //
    // auto runGameLoop = [&application, &window]() {
    //     auto totalTime{0.0};
    //     auto const delta{0.02};
    //
    //     CLOCK.initialize();
    //     auto accumulator{0.0};
    //
    //     while (!window.needsQuit())
    //     {
    //         if (application.hasPendingEvents())
    //         {
    //             application.processEvents();
    //         }
    //
    //         CLOCK.newFrame();
    //         auto const frameTime {CLOCK.timeSinceLastFrame()};
    //
    //         accumulator += frameTime;
    //
    //         while (accumulator >= delta)
    //         {
    //             if window.allowUserInput()
    //             {
    //                 simulate(delta);
    //             }
    //
    //             accumulator -= delta;
    //             totalTime += delta;
    //         }
    //
    //         window.updateGL();
    //     }
    // };
    //
    // QTimer::singleShot(0, runGameLoop);
    //
    // return application.exec();
}
