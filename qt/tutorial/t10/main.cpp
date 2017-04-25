#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QPushButton>

#include "lcdrange.h"
#include "cannonfield.h"

class MyWidget : public QWidget{
    public:
        MyWidget(QWidget * parent = 0);
        ~MyWidget();

};

MyWidget::MyWidget(QWidget *parent) : QWidget(parent){
    QPushButton * quit = new QPushButton(tr("&Quit"));

    quit->setFont(QFont("Times", 18, QFont::Bold));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    LCDRange *angle = new LCDRange;
    angle->setRange(5, 70);

    LCDRange *force = new LCDRange;
    force->setRange(10, 50);

    CannonField *cannonField = new CannonField;

    //quand angle change de valeur
    //ça changent l'angle de l'objet cannonField
    //mais il faut que l'inverse soit vrai aussi
    //pour que ça fonctionne
    connect(angle, SIGNAL(valueChanged(int)),
            cannonField, SLOT(setAngle(int)));
    //quand le cannon change d'angle ça change la valeur
    // de l'objet LCDRange
    connect(cannonField, SIGNAL(angleChanged(int)),
            angle, SLOT(setValue(int)));

    connect(force, SIGNAL(valueChanged(int)),
            cannonField, SLOT(setForce(int)));
    connect(cannonField, SIGNAL(forceChanged(int)),
            force, SLOT(setValue(int)));
    QGridLayout *gridLayout = new QGridLayout;
    QVBoxLayout *leftLayout = new QVBoxLayout;

    leftLayout->addWidget(angle);
    leftLayout->addWidget(force);

    gridLayout->addWidget(quit, 0, 0);
    gridLayout->addLayout(leftLayout, 1, 0);
    gridLayout->addWidget(cannonField, 1, 1, 2, 1);
    gridLayout->setColumnStretch(1, 10);
    setLayout(gridLayout);

    angle->setValue(60);
    angle->setFocus();
    force->setValue(25);
}
MyWidget::~MyWidget(){}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget widget;
    widget.setGeometry(100, 100, 500, 355);
    widget.show();
    return app.exec();
}