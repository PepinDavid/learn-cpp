#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMainWindow>
#include <QLineEdit>
#include <QFormLayout>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QFontComboBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow();

signals:

public slots:

private:
    QMenu *menuFolder;
    QMenu *menuEdit;
    QMenu *menuAffich;
    QMenu *menuHelp;
    QToolBar *toolBar;
    QFontComboBox *choosePolice;
    void createMenus();
    void createActions();
};

#endif // MAINWINDOW_H
