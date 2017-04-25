#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
#include <QDebug>
#include "lcdrange.h"

class MyWidget : public QWidget{
    public:
        MyWidget(QWidget * parent = 0);
        ~MyWidget();

};

MyWidget::MyWidget(QWidget *parent) : QWidget(parent){
    QPushButton * quit = new QPushButton(tr("Quit"));

    quit->setFont(QFont("Times", 18, QFont::Bold));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QGridLayout * grid = new QGridLayout;
    LCDRange *previousRange = 0;

    for(int row = 0; row < 3; ++row){
        for(int columns = 0; columns < 3; ++columns){
            LCDRange * lcdRange = new LCDRange;
            qDebug() << "previous : " << previousRange;
            qDebug() << "lcd : " <<lcdRange;
            grid->addWidget(lcdRange, row, columns);
            //le fait que l'on connect le lcdrange avec son precedent
            //provoque le changement du precedent et ainsi que de suite
            if(previousRange)
                connect(lcdRange, SIGNAL(valueChanged(int)),
                       previousRange, SLOT(setValue(int)));

            previousRange = lcdRange;
            qDebug() << "cpy lcd in previous : " << previousRange;
        }
    }
    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(quit);
    layout->addLayout(grid);
    setLayout(layout);
}
MyWidget::~MyWidget(){}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget widget;
    widget.show();
    return app.exec();
}
