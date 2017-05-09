#include <QApplication>
#include <QWidget>
#include <QLibraryInfo>
#include <QDebug>

#include "principalwindow.h"

int main (int argc, char **argv){
    QApplication app(argc, argv);

    PrincipalWindow winPrincipal;

    winPrincipal.show();
    return app.exec();
}
