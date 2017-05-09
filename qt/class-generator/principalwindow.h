#ifndef PRINCICAPLWINDOW_H
#define PRINCICAPLWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QGridLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QGroupBox>
#include <QLabel>
#include <QMessageBox>

class PrincipalWindow : public QWidget
{
    Q_OBJECT
public:
    explicit PrincipalWindow(QWidget *parent = 0);

signals:

public slots:

private slots:
    void openDialog();
private:
    QGridLayout *m_grid;
    QLabel *m_name;
    QLabel *m_nameMother;
    QLabel *m_nameDate;
    QLabel *m_option;
    QLabel *m_autor;
    QLabel *m_date;
    QLineEdit *m_nameEdit;
    QLineEdit *m_motherEdit;
    QLineEdit *m_autorEdit;
    QDateEdit *m_dateEdit;
    QGroupBox *m_addComment;
    QCheckBox *m_header;
    QCheckBox *m_construct;
    QCheckBox *m_destruct;
    QTextEdit *m_comments;
    QPushButton *m_btnDial;
    QPushButton *m_btnQuit;
};

#endif // PRINCICAPLWINDOW_H
