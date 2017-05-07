#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QGridLayout>

int main(int argc, char **argv){
    QApplication app(argc, argv);

    QWidget window;

    QPushButton *btnQuit = new QPushButton("&Quit");
    QPushButton *btnHello = new QPushButton("Hello");
    QPushButton *btnTest = new QPushButton("Test");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(btnQuit);
    layout->addWidget(btnHello);
    layout->addWidget(btnTest);
    //mumuse avec un pointer
    QPushButton *btn = new QPushButton("&Quit");
    QObject::connect(btn, SIGNAL(clicked(bool)), &app, SLOT(quit()));
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(btn);
    btn = new QPushButton("Hello");;
    vLayout->addWidget(btn);
    btn = new QPushButton("Test");;
    vLayout->addWidget(btn);


    QFormLayout *fLayout = new QFormLayout;

    QLineEdit *nom = new QLineEdit;
    QLineEdit *prenom = new QLineEdit;
    QLineEdit *age = new QLineEdit;

    fLayout->addRow("Votre nom : ", nom);
    fLayout->addRow("Votre prénom : ", prenom);
    fLayout->addRow("Votre âge : ", age);

    QGridLayout *grid = new QGridLayout;
    grid->addLayout(layout, 0, 0);
    grid->addLayout(vLayout, 1, 1);
    grid->addLayout(fLayout, 2, 0, 1, 2);
    //only one by one for test
    //use without grid
    //window.setLayout(layout);
    //window.setLayout(vLayout);

    //grid
    window.setLayout(grid);
    window.show();
    QObject::connect(btnQuit, SIGNAL(clicked(bool)), &app, SLOT(quit()));
    return app.exec();
}
