#include "jsonhttpclient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JsonHttpClient w;
    w.show();
    return a.exec();
}
