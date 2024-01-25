#include "Header/QtEftHelper.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	qputenv("QT_LOGGING_RULES", "qt.network.ssl=true");
    QtEftHelper w;
    w.show();
    return a.exec();
}
