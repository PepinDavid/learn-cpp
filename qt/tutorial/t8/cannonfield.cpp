#include "cannonfield.h"
#include <QPainter>
#include <QDebug>

CannonField::CannonField(QWidget *parent) :
    QWidget(parent)
{
    currentAngle = 45;
    setPalette(QPalette(QColor(250, 250, 200)));
    setAutoFillBackground(true);
}

void CannonField::setAngle(int angle){
    qDebug() << angle;
    if (angle < 5)
        angle = 5;
    if (angle > 70)
        angle = 70;
    if (currentAngle == angle)
        return;
    currentAngle = angle;
    update();
    emit angleChanged(currentAngle);
}

int CannonField::angle() const{
    return currentAngle;
}

void CannonField::paintEvent(QPaintEvent * /*event*/){
    QPainter painter(this);
    painter.drawText(200, 200,
                     tr("Angle = ")+ QString::number(currentAngle));
}

