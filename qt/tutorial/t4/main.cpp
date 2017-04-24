#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>

//creation class heritant de QWidget qui peut etre une
//fenetre de premier plan ou un widget enfant (un pushbutton)
class MyWidget: public QWidget
{
  public:
    //tous constructeur de widget doit inclure une fonction similaire
    MyWidget(QWidget *parent = 0);
    ~MyWidget();
};
//comme tous les widgets il ne fait que passer le parent au
//constructeur de QWidget
MyWidget::MyWidget(QWidget *parent) : QWidget(parent){
    setFixedSize(200, 120);

    QPushButton *quit = new QPushButton(tr("Quit"), this);
    quit->setGeometry(62, 40, 75, 30);
    quit->setFont(QFont("Times", 15, QFont::Bold));

    //qApp est une variable globale se trouvant dans le ".h"
    //de <QApplication>. Il pointe vers l'instance unique de
    //QApplication de l'app
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}
MyWidget::~MyWidget(){

}

int main (int argc, char **argv){
    QApplication app(argc, argv);
    MyWidget myWidget;
    myWidget.show();
    return app.exec();
}
