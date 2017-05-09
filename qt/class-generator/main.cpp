#include <QApplication>
#include <QWidget>
#include <QLibraryInfo>
#include <QDebug>

#include "princicaplwindow.h"

int main (int argc, char **argv){
    QApplication app(argc, argv);

    PrincicaplWindow winPrincipal;

    winPrincipal.show();
    return app.exec();
}
