#include "progression.h"

Progression::Progression(QWidget *parent) : QWidget(parent)
{
    m_layout = new QVBoxLayout;

    m_btn = new QPushButton("&Quit");

    m_slider = new QSlider(Qt::Horizontal);
    m_slider->setGeometry(10, 80, 280, 20);
    m_slider->setToolTip("change values of progress and LCD");

    m_progress = new QProgressBar;
    m_progress->setGeometry(10, 110, 250, 20);
    m_progress->setTextVisible(true);

    m_layout->addWidget(m_progress);
    m_layout->addWidget(m_slider);
    m_layout->addWidget(m_btn);

    connect(m_btn, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
    connect(m_slider, SIGNAL(valueChanged(int)), m_progress, SLOT(setValue(int)));
    this->setLayout(m_layout);
}
