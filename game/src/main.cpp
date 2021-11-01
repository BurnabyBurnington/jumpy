#include <QApplication>
#include <QDebug>

#include <window.h>


int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    game::Window window {};
    window.show();

    auto getNow = [](){
        return std::chrono::high_resolution_clock::now();
    };

    auto t{0.0};
    auto const dt{0.1};
    auto quit{false};

    auto currentTime = getNow();
    auto accumulator{0.0};

    while (true)
    {
        if (application.hasPendingEvents())
        {
            application.processEvents();
        }

        auto newTime = getNow();
        auto frameTime = std::chrono::duration<double>(newTime - currentTime).count();
        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= dt)
        {
            window.myUpdate(dt);
            accumulator -= dt;
            t += dt;
        }

        window.updateGL();
    }

    return application.exec();
}
