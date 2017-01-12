#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton btn("Salut vous !");
    btn.show();

    return app.exec();
}
