#ifndef CANNONFIELD_H
#define CANNONFIELD_H

#include <QWidget>
#include <QPaintEvent>

class CannonField : public QWidget
{
    Q_OBJECT
    public:
        explicit CannonField(QWidget *parent = 0);
        int angle() const;
    signals:
        void angleChanged(int newAngle);
    public slots:
        void setAngle(int angle);
    protected:
        void paintEvent(QPaintEvent * event);
    private:
        int currentAngle;
};

#endif // CANNONFIELD_H
