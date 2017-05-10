#include "mainwindow.h"

MainWindow::MainWindow()
{
    //zone central type SDI (Single Document Interface)
//    QWidget *centralArea = new QWidget();
//    setCentralWidget(centralArea);

    //zone central type MDI (Multiple Document Interface)
    QMdiArea *centralAreaMdi = new QMdiArea();
    QWidget *winOne = new QWidget();
    QWidget *winTwo = new QWidget();
    setCentralWidget(centralAreaMdi);


    QFormLayout *layoutOne = new QFormLayout();
    QFormLayout *layoutTwo = new QFormLayout();

    QLineEdit *name = new QLineEdit();
    QLineEdit *surname = new QLineEdit();
    QLineEdit *age = new QLineEdit();

    QLineEdit *sex = new QLineEdit();
    QLineEdit *colorEyes = new QLineEdit();

    layoutOne->addRow("Votre nom : ", name);
    layoutOne->addRow("Votre prénom : ", surname);
    layoutOne->addRow("Votre âge : ", age);

    layoutTwo->addRow("Votre sexe : ", sex);
    layoutTwo->addRow("La couleur de vos yeux : ", colorEyes);

    //for SDI/MDI
    createMenus();
    createActions();
    //for SDI
//    layoutOne->setMargin(5);
//    centralArea->setLayout(layoutOne);
//    setWindowTitle(tr("Menus"));
//    setMinimumSize(220, 220);
//    resize(280, 280);

    //for MDI
    winOne->setLayout(layoutOne);
    winTwo->setLayout(layoutTwo);
    QMdiSubWindow *firstSubWin = centralAreaMdi->addSubWindow(winOne);
    QMdiSubWindow *secondSubWin = centralAreaMdi->addSubWindow(winTwo);
}

//for SDI/MDI
void MainWindow::createMenus(){
    menuFolder = menuBar()->addMenu("&Fichier");
    menuEdit = menuBar()->addMenu("&Edit");
    menuAffich = menuBar()->addMenu("&Affich");
    menuHelp = menuBar()->addMenu("&Help");

    toolBar = addToolBar("Files");
}

void MainWindow::createActions(){
    QAction *quit = new QAction("&Quit", this);
    menuFolder->addAction(quit);
    toolBar->addAction(quit);
    toolBar->addSeparator();
    choosePolice = new QFontComboBox();
    toolBar->addWidget(choosePolice);
    quit->setShortcut(QKeySequence("Ctrl+Q"));
    connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
}
