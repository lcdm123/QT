#include "jsq.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JSQ w;
    w.show();

    return a.exec();
}

