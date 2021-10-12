#include <QApplication>
#include <QDebug>
#include <QLabel>

#include <window.h>


int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    engine::Window window {};
    window.show();

    qDebug() << "Hello World";

    return application.exec();
}
