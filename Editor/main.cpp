#include "editor.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
   // Editor::setCodecForTr(Editor::codecForLocale());

    QApplication a(argc, argv);
    Editor w;
    w.show();
    return a.exec();
}
