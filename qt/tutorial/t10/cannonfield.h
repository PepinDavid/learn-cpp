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
        int force() const;
    signals:
        void angleChanged(int newAngle);
        void forceChanged(int newForce);
    public slots:
        void setAngle(int angle);
        void setForce(int force);
    protected:
        void paintEvent(QPaintEvent * event);
    private:
        QRect cannonRect() const;
        int currentAngle;
        int currentForce;
};

#endif // CANNONFIELD_H
