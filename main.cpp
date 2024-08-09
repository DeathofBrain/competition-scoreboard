#include "counter.h"

#include <QApplication>
int main(int argc, char *argv[])
{
    qputenv("QT_SCALE_FACTOR", "2.0");
    QApplication a(argc, argv);
    counter w;
    w.show();
    //w.showFullScreen();
    return a.exec();
}
