#include <iostream>

#include <QtWidgets\qapplication.h>


int main(int argc, char* argv[])
{
    QApplication application{argc, argv};

    // TODO: Remove this line, later
	std::cout << "Hello, World!\n";

    return application.exec();
}
