#include "QtEftHelper.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtEftHelper w;
    w.show();
    return a.exec();
}
