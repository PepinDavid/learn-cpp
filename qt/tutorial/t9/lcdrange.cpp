#include <QLCDNumber>
#include <QSlider>
#include <QVBoxLayout>

#include "lcdrange.h"

LCDRange::LCDRange(QWidget *parent) : QWidget(parent){
    QLCDNumber *lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Filled);

    slider = new QSlider(Qt::Horizontal);
    slider->setRange(0,99);
    slider->setValue(0);
    connect(slider, SIGNAL(valueChanged(int)),
                lcd, SLOT(display(int)));
    //pour le mecanisme de changement de valeur
    //en cascade/reciproque d'un objet slider
    //ou un objet qui envoie une valeur int
    // et l'objet this 
    connect(slider, SIGNAL(valueChanged(int)),
                this, SIGNAL(valueChanged(int)));
    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(lcd);
    layout->addWidget(slider);

    setLayout(layout);
    setFocusProxy(slider);
}

LCDRange::~LCDRange(){}

int LCDRange::value() const{
    return slider->value();
}

void LCDRange::setValue(int value){
    slider->setValue(value);
}

void LCDRange::setRange(int minVal, int maxVal){
    if(minVal < 0 || maxVal > 99 || minVal > maxVal){
        qWarning("LCDRange::setRange(%d, %d)\n"
                          "\tRange must be 0..99\n"
                          "\tand minValue must not be greater than maxValue",
                          minVal, maxVal);
                 return;
    }
    slider->setRange(minVal, maxVal);
}
