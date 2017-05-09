#ifndef PRINCICAPLWINDOW_H
#define PRINCICAPLWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QGroupBox>

class PrincicaplWindow : public QWidget
{
    Q_OBJECT
public:
    explicit PrincicaplWindow(QWidget *parent = 0);

signals:

public slots:

private:
    QGridLayout *grid;

};

#endif // PRINCICAPLWINDOW_H
