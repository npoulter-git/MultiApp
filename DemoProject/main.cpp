#include "DemoProject.h"
#include "LoginScreen.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginScreen w;
    w.show();
    return a.exec();
}
