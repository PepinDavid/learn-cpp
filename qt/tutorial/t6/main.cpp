#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>

class LCDRange : public QWidget{
    public:
        LCDRange(QWidget * parent = 0);
        ~LCDRange();
};
LCDRange::LCDRange(QWidget *parent){
    QLCDNumber *lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Filled);

    QSlider *slider = new QSlider(Qt::Horizontal);
}
LCDRange::~LCDRange(){}
