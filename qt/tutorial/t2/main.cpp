#include <QApplication>
#include <QFont>
#include <QPushButton>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QPushButton quit("Quit");
   quit.resize(300, 100);
   quit.setFont(QFont("Times", 18, QFont::Bold));
   //QObject::connect fonction statique
   // !!! etabli une connexion a sens unique avec le widget mis en reference
   // Tous les objets peuvent envoyer un/des signal/signaux et pour les recevoir utilise des SLOTs
   QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

   quit.show();
   return app.exec();
}
