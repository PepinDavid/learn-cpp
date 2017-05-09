#include "windial.h"

WinDial::WinDial(QString &string, QWidget *parent) :
    QDialog(parent)
{
    m_vLayout = new QVBoxLayout();
    m_code = new QTextEdit();
    m_code->setPlainText(string);
    m_code->setReadOnly(true);

    m_btnClose = new QPushButton("Close");
    m_vLayout->addWidget(m_code);
    m_vLayout->addWidget(m_btnClose);

    setLayout(m_vLayout);

    connect(m_btnClose, SIGNAL(clicked()), this, SLOT(close()));
}
