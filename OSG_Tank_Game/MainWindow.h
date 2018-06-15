#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <osgQt/QWidgetImage>
#include <osg/Group>
#include "ui_mainwindow.h"
#include "QOSGViewWidget.h"
#include "GameSplashWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void resizeEvent(QResizeEvent * event);
    virtual void showEvent(QShowEvent *event);

private:
    /*
     *@brief:   ´´½¨»¶Ó­»­Ãæ
     *@author:  dgy
     *@date: 2018/06/15
     */
    QWidget* CreateSplash();
    void InitOSGViewWidget();

    void CreateConnect();

private slots:

    void StartGameSlot();

private:
    Ui::MainWindowClass ui;
    OSGViewWidget* m_pOSGWidget;
    osg::ref_ptr<osgQt::QWidgetImage> m_pSplashWidgetImage;
    GameSplashWidget* m_pWidget;
    osg::ref_ptr<osg::Group> m_RootNode;
};

#endif // MAINWINDOW_H
