#ifndef PROGRESSION_H
#define PROGRESSION_H

#include <QApplication>
#include <QWidget>
#include <QProgressBar>
#include <QSlider>
#include <QPushButton>
#include <QVBoxLayout>

class Progression : public QWidget
{
    Q_OBJECT
public:
    explicit Progression(QWidget *parent = 0);

signals:

public slots:

private:
    QVBoxLayout *m_layout;
    QPushButton *m_btn;
    QSlider *m_slider;
    QProgressBar *m_progress;
};

#endif // PROGRESSION_H
