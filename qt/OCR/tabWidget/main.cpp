#include <QApplication>
#include <QWidget>
#include <QTabWidget>
#include <QGridLayout>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QDebug>

#include "info.h"
#include "progression.h"
int main(int argc, char ** argv){
    QApplication app(argc, argv);

    QWidget *window = new QWidget;

    QGridLayout *grid = new QGridLayout;
    QTabWidget *tab = new QTabWidget(window);
    QWidget *widget = new Info();
    QWidget *widgetProg = new Progression();
    tab->addTab(widget, "Information");
    tab->addTab(widgetProg, "Progression");
    qDebug() << "info ptr : " << widget;
    qDebug() << "info ptr : " << widgetProg;

//    QObjectList list = tab->children();
//    for(int i = 0; i < 2; ++i)
//        qDebug() << &list[i];
    //for traduction
    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&translator);

    grid->addWidget(tab, 1, 1, 3, 3);
    window->setLayout(grid);
    window->show();
    return app.exec();
}
