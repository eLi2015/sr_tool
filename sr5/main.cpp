#include "shadowruntool.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShadowrunTool w;
    w.show();


    const int retVal = a.exec();

    w.on_closing();

    return retVal;
}
