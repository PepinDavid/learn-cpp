#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QProgressBar>
#include <QMessageBox>
#include <QString>
#include <QInputDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QPalette>
#include <QColor>
#include <QLabel>

class MyWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MyWindow(QWidget *parent = 0);

signals:

public slots:
    void changeWidth(int width);
    void changeHeight(int height);
    void openDialHello();
    void openDialQuestion();
    void openDialText();
    void openChangeFont();
    void openChangeColor();
private:
    int minWidth;
    int minHeight;
    QString m_s;
    QPushButton *m_button;
    QPushButton *m_reset;
    QPushButton *m_btnDialHello;
    QPushButton *m_btnDialQestion;
    QPushButton *m_btnDialText;
    QPushButton *m_btnPoliceText;
    QPushButton *m_btnColorText;

    QLCDNumber *m_lcd;

    QSlider *m_slider;
    QSlider *m_sHeight;
    QSlider *m_sWidth;

    QProgressBar *m_progress;

    QLabel *m_label;
};

#endif // MYWINDOW_H
