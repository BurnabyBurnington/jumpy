#include <QApplication>
#include <QDebug>

#include <window.h>


int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    game::Window window {};
    window.show();

    return application.exec();
}
