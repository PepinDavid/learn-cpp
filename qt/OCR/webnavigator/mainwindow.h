#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QtWebKitWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow();

signals:

public slots:
    void undo();
    void redo();
    void home();
    void stop();
    void actualise();

    void about();
    void newTab();
    void closeTab();
    void loadPage();
    void changeTab(int index);

    void changeTitle(const QString &fullTitle);
    void changeUrl(const QUrl &url);
    void loadBegin();
    void loadInProgress(int percent);
    void loadEnd(bool ok);

private:
    QTabWidget *m_tabs;

    QLineEdit *m_url;
    QProgressBar *m_progress;

    QAction *actNewTab;
    QAction *actCloseTab;
    QAction *actQuit;
    QAction *actRedo;
    QAction *actUndo;
    QAction *actAbout;
    QAction *actPrevious;
    QAction *actNext;
    QAction *actStop;
    QAction *actActualise;
    QAction *actHome;
    QAction *actGo;

    void createMenus();
    void createActions();
    void createToolBar();
    void createStateBar();
    QWidget *createNewTab(QString url = "");
    QWebView *actualPage();
};

#endif // MAINWINDOW_H
