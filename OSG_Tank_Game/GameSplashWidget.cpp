#include "GameSplashWidget.h"

GameSplashWidget::GameSplashWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    this->setWindowOpacity(1);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    ui.label_splash_img->setPixmap(QPixmap(":/MainWindow/Resources/tank.jpg"));
    ConnectSignal();
}

GameSplashWidget::~GameSplashWidget()
{

}

void GameSplashWidget::ConnectSignal()
{
    connect(ui.pushButton_start_game, &QPushButton::clicked, this, &GameSplashWidget::StartGame);
}

void GameSplashWidget::StartGame()
{
    emit StartGameSignal();
}
