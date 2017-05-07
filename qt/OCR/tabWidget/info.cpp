#include "info.h"

Info::Info(QWidget *parent) : QWidget(parent)
{
    m_layout = new QHBoxLayout;

    m_edit = new QLineEdit("Votre nom");
    m_layout->addWidget(m_edit);

    m_btn = new QPushButton("&Quit");
    m_layout->addWidget(m_btn);
    connect(m_btn, SIGNAL(clicked(bool)), qApp, SLOT(quit()));

    m_btn = new QPushButton("&Coucou");
    m_layout->addWidget(m_btn);
    connect(m_btn, SIGNAL(clicked(bool)), this, SLOT(openDial()));
    this->setLayout(m_layout);
}
void Info::openDial(){
    QMessageBox::information(this, "Hello Title", "Hello the <strong>World ! </strong>");
}
