#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //creation d'une fenetre
    QWidget window;
    window.setFixedSize(500, 250);
    //creation d'un bouton, ayant pour parent la fenetre
    QPushButton btn("Salut vous !", &window);
    QLabel lbl("Salut toi", &window);
    lbl.move(75,0);
    lbl.setFont(QFont("Courrier", 12, QFont::Bold, true));
    btn.move(60, 50);
    btn.setFont(QFont("Comic Sans MS", 20, QFont::Bold, true));
    btn.setCursor(Qt::PointingHandCursor);
    btn.setToolTip("Hello");

    window.show();

    return app.exec();
}
