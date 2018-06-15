#ifndef GAMESPLASHWIDGET_H
#define GAMESPLASHWIDGET_H

#include <QWidget>
#include "ui_gamesplashwidget.h"

class GameSplashWidget : public QWidget
{
    Q_OBJECT

public:
    GameSplashWidget(QWidget *parent = 0);
    ~GameSplashWidget();

private:
    void ConnectSignal();

private slots:
    void StartGame();

signals:
    void StartGameSignal();

private:
    Ui::GameSplashWidget ui;
};

#endif // GAMESPLASHWIDGET_H
