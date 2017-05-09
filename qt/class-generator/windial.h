#ifndef WINDIAL_H
#define WINDIAL_H

#include <QWidget>
#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QString>
#include <QDebug>
#include <QVBoxLayout>

class WinDial : public QDialog
{
    Q_OBJECT
public:
    explicit WinDial(QString &string, QWidget *parent = 0);

signals:

public slots:

private:
    QTextEdit *m_code;
    QPushButton *m_btnClose;
    QVBoxLayout *m_vLayout;
};

#endif // WINDIAL_H
