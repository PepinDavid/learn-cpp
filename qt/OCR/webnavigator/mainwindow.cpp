#include "mainwindow.h"

MainWindow::MainWindow(){
    createActions();
    createMenus();
    createToolBar();
    createStateBar();

    m_tabs = new QTabWidget();
    m_tabs->addTab(createNewTab("http://www.google.fr"), tr("New Tab"));
    connect(m_tabs, SIGNAL(currentChanged(int)), this, SLOT(changeTab(int)));
    setCentralWidget(m_tabs);
    setMinimumSize(500, 350);
}
void MainWindow::createActions(){
    actNewTab = new QAction(tr("&Nouvel onglet"), this);
    actNewTab->setShortcut(tr("Ctrl+T"));
    connect(actNewTab, SIGNAL(triggered()), this, SLOT(newTab()));
    actCloseTab = new QAction(tr("&Fermer l'onglet"), this);
    actCloseTab->setShortcut(tr("Ctrl+W"));
    connect(actCloseTab, SIGNAL(triggered()), this, SLOT(closeTab()));
    actQuit = new QAction(tr("&Quitter"), this);
    actQuit->setShortcut(tr("Ctrl+Q"));
    connect(actQuit, SIGNAL(triggered()), qApp, SLOT(quit()));

    actUndo = new QAction(QIcon("images/precedente.png"), tr("&Precedente"), this);
    actUndo->setShortcut(QKeySequence::Back);
    connect(actUndo, SIGNAL(triggered()), this, SLOT(undo()));
    actNext = new QAction(QIcon("images/suivante.png"), tr("&Suivante"), this);
    actNext->setShortcut(QKeySequence::Forward);
    connect(actNext, SIGNAL(triggered()), this, SLOT(redo()));
    actStop = new QAction(QIcon("images/stop.png"), tr("S&top"), this);
    connect(actStop, SIGNAL(triggered()), this, SLOT(stop()));
    actActualise = new QAction(QIcon("images/actualiser.png"), tr("&Actualiser"), this);
    actActualise->setShortcut(QKeySequence::Refresh);
    connect(actActualise, SIGNAL(triggered()), this, SLOT(actualise()));
    actHome = new QAction(QIcon("images/accueil.png"), tr("A&ccueil"), this);
    connect(actHome, SIGNAL(triggered()), this, SLOT(home()));
    actGo = new QAction(QIcon("images/go.png"), tr("A&ller à"), this);
    connect(actGo, SIGNAL(triggered()), this, SLOT(loadPage()));

    actAbout = new QAction(tr("&A propos..."), this);
    connect(actAbout, SIGNAL(triggered()), this, SLOT(about()));
    actAbout->setShortcut(QKeySequence::HelpContents);
}
void MainWindow::createToolBar(){
    m_url = new QLineEdit();
    connect(m_url, SIGNAL(returnPressed()), this, SLOT(loadPage()));

    QToolBar *m_toolbar = addToolBar(tr("Navigation"));
    m_toolbar->addWidget(m_url);
}
void MainWindow::createStateBar(){
    m_progress = new QProgressBar(this);
    m_progress->setVisible(false);
    m_progress->setMaximumHeight(14);
    statusBar()->addWidget(m_progress, 1);
}

void MainWindow::createMenus(){
    m_menuFile = menuBar()->addMenu(tr("&File"));
    m_menuFile->addAction(actNewTab);
    m_menuFile->addAction(actCloseTab);
    m_menuFile->addSeparator();
    m_menuFile->addAction(actQuit);

    QMenu *m_menuEdit = menuBar()->addMenu(tr("&Edit"));

    QMenu *m_menuNavigation = menuBar()->addMenu(tr("&Navigation"));
    m_menuNavigation->addAction(actUndo);
    m_menuNavigation->addAction(actRedo);
    m_menuNavigation->addAction(actStop);
    m_menuNavigation->addAction(actHome);
    m_menuNavigation->addAction(actActualise);

    QMenu *m_menuAbout = menuBar()->addMenu("?");
    m_menuAbout->addAction(actAbout);
}
QWidget* MainWindow::createNewTab(QString url){
    QWidget *newTab = new QWidget();
    QWebView *webPage = new QWebView();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(webPage);
    newTab->setLayout(layout);

    if(url.isEmpty())
        webPage->load(QUrl("http://www.google.fr"));
    else{
        if(url.left(7) != "http://")
            url = "http://"+url;
        webPage->load(QUrl(url));
    }
    connect(webPage, SIGNAL(titleChanged(QString)), this, SLOT(changeTitle(QString)));
    connect(webPage, SIGNAL(urlChanged(QUrl)), this, SLOT(changeUrl(QUrl)));
    connect(webPage, SIGNAL(loadStarted()), this, SLOT(loadBegin()));
    connect(webPage, SIGNAL(loadProgress(int)), this, SLOT(loadInProgress(int)));
    connect(webPage, SIGNAL(loadFinished(bool)), this, SLOT(loadEnd(bool)));
    return newTab;
}
QWebView* MainWindow::actualPage(){
    return m_tabs->currentWidget()->findChild<QWebView *>();
}
void MainWindow::undo(){
    actualPage()->back();
}
void MainWindow::redo(){
    actualPage()->forward();
}
void MainWindow::home(){
    actualPage()->load(QUrl("http://www.google.com"));
}
void MainWindow::stop(){
    actualPage()->stop();
}
void MainWindow::actualise(){
    actualPage()->reload();
}

void MainWindow::about(){
    QMessageBox::information(this, "about", "Test Exo create browser navigator with QT5");
}
void MainWindow::newTab(){
    int indexNewTab = m_tabs->addTab(createNewTab(), "New Page");
    m_tabs->setCurrentIndex(indexNewTab);

    m_url->setText("");
    m_url->setFocus(Qt::OtherFocusReason);
}
void MainWindow::closeTab(){
    if(m_tabs->count() > 1)
        m_tabs->removeTab(m_tabs->currentIndex());

}
void MainWindow::loadPage(){
    QString url = m_url->text();

    if(url.left(7) != "http://")
        url = "http://"+url, m_url->setText(url);
    actualPage()->load(QUrl(url));
}

void MainWindow::changeTab(int index){
    changeTitle(actualPage()->title());
    changeUrl(actualPage()->url());
}

void MainWindow::changeTitle(const QString &fullTitle){
    if(fullTitle.size() > 40)
        //fullTitle = fullTitle.left(40)+"...";
    setWindowTitle(fullTitle);
    m_tabs->setTabText(m_tabs->currentIndex(), fullTitle);
}
void MainWindow::changeUrl(const QUrl &url){
    if(url.toString() != "html/page_blanche.html")
        m_url->setText(url.toString());
}
void MainWindow::loadBegin(){
    m_progress->setVisible(true);
}
void MainWindow::loadInProgress(int percent){
    m_progress->setValue(percent);
}
void MainWindow::loadEnd(bool ok){
    m_progress->setVisible(false);
    statusBar()->showMessage("ready", 2000);
}
