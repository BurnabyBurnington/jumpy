// #include <iostream>
//
// #include <QtCore\QDebug>
// #include <QtWidgets\qapplication.h>
// #include <QtWidgets\qlabel.h>
//
//
// int main(int argc, char* argv[])
// {
//     QCoreApplication application{argc, argv};
//
// 	qDebug() << "Hello, World!";
//
// 	QLabel mywidget {"SOMETHING HERE"};
// 	mywidget.show();
//     //
// 	// application.setMainWidget(mywidget)
//     //
//     // // TODO: Remove this line, later
// 	// std::cout << "Hello, World2!\n";
//
//     return application.exec();
// }
#include <QLabel>
#include <QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	QLabel mywidget {"SOMETHING HERE"};
	mywidget.show();

    qDebug() << "Hello World";

    return a.exec();
}
