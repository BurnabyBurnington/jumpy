#include <QApplication>
#include <QDebug>
#include <QLabel>


int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

	QLabel mywidget {"SOMETHING HERE"};
	mywidget.show();

    qDebug() << "Hello World";

    return application.exec();
}
