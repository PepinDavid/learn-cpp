#include <QApplication>
#include <QWebView>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QWebView view;
//    view.show();
//    view.load(QUrl("http://google.com"));
    MainWindow main = new MainWindow();
    main->show();

    return a.exec();
}
