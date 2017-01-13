#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //creation d'une fenetre
    QWidget window;
    window.setFixedSize(300, 150);
    //creation d'un bouton, ayant pour parent la fenetre
    QPushButton btn("Salut vous !", &window);
    btn.move(60, 50);
    btn.setFont(QFont("Comic Sans MS", 14));
    btn.setCursor(Qt::PointingHandCursor);
    btn.setToolTip("Hello");

    window.show();

    return app.exec();
}
