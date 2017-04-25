#ifndef LCDRANGE_H
#define LCDRANGE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QSlider;
QT_END_NAMESPACE

class LCDRange : public QWidget{
    Q_OBJECT
    public:
        LCDRange(QWidget * parent = 0);
        ~LCDRange();
        int value() const;
    public slots:
        void setValue(int value);
    signals:
        void valueChanged(int newValue);
    private:
        QSlider *slider;
};

#endif // LCDRANGE_H
