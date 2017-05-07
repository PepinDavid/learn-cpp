#ifndef INFO_H
#define INFO_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QMessageBox>

class Info : public QWidget
{
    Q_OBJECT
public:
    explicit Info(QWidget *parent = 0);

signals:

public slots:
    void openDial();
private:
    QLineEdit *m_edit;
    QPushButton *m_btn;
    QHBoxLayout *m_layout;
};

#endif // INFO_H
