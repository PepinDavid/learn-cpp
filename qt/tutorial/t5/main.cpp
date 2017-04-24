#include <QApplication>
#include <QFont>
#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

class MyWidget : public QWidget{
    public:
        MyWidget(QWidget *parent = 0);
        ~MyWidget();
};
MyWidget::MyWidget(QWidget *parent) : QWidget(parent) {
    QPushButton *quit = new QPushButton(tr("Quit"));
    quit->setFont(QFont("Times", 18, QFont::Bold));

    //creation de quatre boutons pour changer le mode
    //de comptage de lcd
    QPushButton *hex = new QPushButton(tr("HEX"));
    QPushButton *dec = new QPushButton(tr("DEC"));
    QPushButton *oct = new QPushButton(tr("OCT"));
    QPushButton *bin = new QPushButton(tr("BIN"));
    hex->setFont(QFont("Courrier", 10, QFont::Black));
    dec->setFont(QFont("Courrier", 10, QFont::Black));
    oct->setFont(QFont("Courrier", 10, QFont::Black));
    bin->setFont(QFont("Courrier", 10, QFont::Black));

    //widget qui affiche un nombre dans un ecran LCD
    QLCDNumber *lcd = new QLCDNumber(6);
    //cette methode rend les nombres plus lisible
    lcd->setSegmentStyle(QLCDNumber::Filled);

    //widget qui affiche une barre pour changer une valeur entiere comprise
    //entre 0 et 99
    //valeur init = 0
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100000);
    slider->setValue(0);

    QSpinBox *spin = new QSpinBox();
    spin->setRange(0, 100000);
    spin->setValue(0);

    //on connect notre bouton et l'application entre elle
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    //on connecte le slider avec l'afficheur lcd
    connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

    connect(spin, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

    //on connecte les boutons pour changer le base de numeration du lcd
    connect(hex, SIGNAL(clicked()), lcd, SLOT(setHexMode()));
    connect(dec, SIGNAL(clicked()), lcd, SLOT(setDecMode()));
    connect(oct, SIGNAL(clicked()), lcd, SLOT(setOctMode()));
    connect(bin, SIGNAL(clicked()), lcd, SLOT(setBinMode()));
    //sert a gerer la taille et la position des widgets enfants
    //utiliser un layout permet de ne pas se soucier de la position des enfants
    QVBoxLayout *layout = new QVBoxLayout;
    //on ajoute les widgets enfants au layout
    layout->addWidget(quit);
    layout->addWidget(lcd);
    layout->addWidget(slider);
    layout->addWidget(spin);

    layout->addWidget(hex);
    layout->addWidget(dec);
    layout->addWidget(oct);
    layout->addWidget(bin);
    //rend automatiquement les widgets dans le layout enfant de MyWidget
    //pas besoin de specifier le lien de parentes
    setLayout(layout);
}
MyWidget::~MyWidget(){}

int main (int argc, char **argv){
    QApplication app(argc, argv);
    MyWidget mywidget;
    mywidget.show();
    return app.exec();
}
