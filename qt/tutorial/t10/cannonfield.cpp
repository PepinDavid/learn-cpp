#include "cannonfield.h"
#include <QPainter>
#include <QDebug>

CannonField::CannonField(QWidget *parent) :
    QWidget(parent)
{
    currentAngle = 45;
    currentForce = 0;
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
    update(cannonRect());
    emit angleChanged(currentAngle);
}

void CannonField::setForce(int force){
    qDebug() << force;
    if(force < 0)
        force = 0;
    if(currentForce == force)
        return;
    currentForce = force;
    emit forceChanged(currentForce);
}

int CannonField::angle() const{
    return currentAngle;
}
int CannonField::force() const{
    return currentForce;
}

void CannonField::paintEvent(QPaintEvent * /*event*/){
    QPainter painter(this);
    painter.setPen(Qt::SolidLine);
    painter.setBrush(Qt::blue);
    painter.translate(0, rect().height());
    painter.drawPie(QRect(-35, -35, 70, 70), 0, 90 * 16);
    painter.rotate(-currentAngle);
    painter.drawRect(QRect(30, -5, 20, 10));
    painter.drawText(200, 200,
                     tr("Angle = ")+ QString::number(currentAngle));
}

QRect CannonField::cannonRect() const{
    QRect result(0, 0, 50, 50);
    result.moveBottomLeft(rect().bottomLeft());
    return result;
}
