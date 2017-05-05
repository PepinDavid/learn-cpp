#include "mywindow.h"

MyWindow::MyWindow(QWidget *parent) :
    QWidget(parent)
{
    minHeight = 300;
    minWidth = 350;
    m_s = "";

    //size de la fenetre
    setFixedSize(minWidth, minHeight);

    //creation du bouton quitter
    m_button = new QPushButton("&Quit", this);
    m_button->setFont(QFont("Arial", 14));
    m_button->setCursor(Qt::PointingHandCursor);
    m_button->move(10 ,10);

    //instance button rest
    m_reset = new QPushButton("&Reset", this);
    m_reset->setFont(QFont("Comic Sans MS", 8));
    m_reset->move(10, 130);

    //instance label
    m_label = new QLabel("Your alias is : " + m_s, this);
    m_label->move(10+ m_button->width(), 10);

    //instance LCD
    m_lcd = new QLCDNumber(this);
    m_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_lcd->move(110, 50);

    //instance bar slide
    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(10, 80, 280, 20);
    m_slider->setToolTip("change values of progress and LCD");

    //instance slider for width
    m_sWidth = new QSlider(Qt::Horizontal, this);
    m_sWidth->setGeometry(10, 190, 280, 15);
    m_sWidth->setRange(minWidth, 800);
    //instance slider for height
    m_sHeight = new QSlider(Qt::Vertical, this);
    m_sHeight->setGeometry(300, 10, 15, 190);
    m_sHeight->setRange(minHeight, 600);

    //instance btnDialhello for open Hello pop-up
    m_btnDialHello = new QPushButton("Open Hello", this);
    m_btnDialHello->setFont(QFont("Times", 8));
    m_btnDialHello->move(10+m_reset->width(), 130);
    //instance btnDial for open question
    m_btnDialQestion= new QPushButton("Open Question", this);
    m_btnDialQestion->setFont(QFont("Times", 8));
    m_btnDialQestion->move(10+m_btnDialHello->width()+m_reset->width(), 130);
    //instance btnDialText for open dialog
    m_btnDialText= new QPushButton("What's alias", this);
    m_btnDialText->setFont(QFont("Times", 8));
    m_btnDialText->move(10, 130+m_btnDialHello->height());
    //instance m_btnPoliceText for open change police type
    m_btnPoliceText= new QPushButton("Change Police", this);
    m_btnPoliceText->setFont(QFont("Times", 8));
    m_btnPoliceText->move(10+m_btnDialText->width(), 130+m_btnDialHello->height());
    //instance m_btnColorText for open change color
    m_btnColorText= new QPushButton("Change Color", this);
    m_btnColorText->setFont(QFont("Times", 8));
    m_btnColorText->move(10+m_btnDialHello->width()+m_btnPoliceText->width(), 130+m_btnDialHello->height());

    //instance progress bar
    m_progress = new QProgressBar(this);
    m_progress->setGeometry(10, 110, 250, 20);
    m_progress->setTextVisible(true);

    //connection clic bouton a la fermeture de la fenetre
    QObject::connect(m_button, SIGNAL(clicked()), qApp, SLOT(quit()));
    //connexion event clicked button a progress bar
    QObject::connect(m_reset, SIGNAL(clicked()), m_progress, SLOT(reset()));
    //connect event clicked btnDialHello for open pop-up Hello
    QObject::connect(m_btnDialHello, SIGNAL(clicked()), this, SLOT(openDialHello()));
    //connect event clicked btnDialQuestion for open pop-up Question
    QObject::connect(m_btnDialQestion, SIGNAL(clicked()), this, SLOT(openDialQuestion()));
    //connect event clicked btnDialText for open pop-up prompt
    QObject::connect(m_btnDialText, SIGNAL(clicked()), this, SLOT(openDialText()));
    //
    QObject::connect(m_btnPoliceText, SIGNAL(clicked()), this, SLOT(openChangeFont()));
    //
    QObject::connect(m_btnColorText, SIGNAL(clicked()), this, SLOT(openChangeColor()));

    //connexion event value change slider a affichage lcd
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int)));
    //connexion event value change slider a pogress bar
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_progress, SLOT(setValue(int)));

    //connexion event value change slider Width to width window
    QObject::connect(m_sWidth, SIGNAL(valueChanged(int)), this, SLOT(changeWidth(int)));
    //connexion event value change slider Height to height window
    QObject::connect(m_sHeight, SIGNAL(valueChanged(int)), this, SLOT(changeHeight(int)));
}

void MyWindow::changeWidth(int w){
    setFixedWidth(w);
}

void MyWindow::changeHeight(int h){
    setFixedHeight(h);
}

void MyWindow::openDialHello(){
    QMessageBox::information(this, "Title Hello", "Hello the <strong>World !</strong>");
}

void MyWindow::openDialQuestion(){
    int rep = QMessageBox::question(this, "Title Health", "Are you fine ?", (QMessageBox::Yes | QMessageBox::No));

    if(rep == QMessageBox::Yes)
        QMessageBox::information(this, "Title Health", "Good");
    else if(rep == QMessageBox::No)
        QMessageBox::critical(this, "Title Health", "Ooh, sorry");
}

void MyWindow::openDialText(){
    bool ok = false;
    m_s = QInputDialog::getText(this, "Alias", "What's your alias ?", QLineEdit::Normal, QString(), &ok);
    if (ok && !m_s.isEmpty()){
       QMessageBox::information(this, "Pseudo", "Bonjour " + m_s + ", ça va ?");
       m_label->setText("Your alias is : "+m_s);
    }else
       QMessageBox::critical(this, "Pseudo", "Vous n'avez pas voulu donner votre nom… snif.");
}

void MyWindow::openChangeFont(){
    bool ok = false;
    QFont police = QFontDialog::getFont(&ok, m_label->font(), this, "Choose a police");
    if(ok)
        m_label->setFont(police);
}
void MyWindow::openChangeColor(){
    QColor color = QColorDialog::getColor(Qt::white, this);
    QPalette palette;
    palette.setColor(QPalette::ButtonText, color);
    m_btnColorText->setPalette(palette);
}
