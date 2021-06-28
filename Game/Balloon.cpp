#include "Balloon.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"
#include <QKeyEvent>
#include "Explosion.h"
#include <QMouseEvent>
#include <QtWidgets>

extern Game * game;

Balloon::Balloon(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    QString paths[] = {
        ":/images/D:/img/balloon1.png",
        ":/images/D:/img/balloon2.png",
        ":/images/D:/img/balloon3.png",
        ":/images/D:/img/balloon4.png",
        ":/images/D:/img/balloon5.png",
        ":/images/D:/img/balloon6.png"
    };

    int random_num = rand()%1200;
    setPos(random_num, 720);

    setPixmap(QPixmap(paths[rand() % 6]));
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(25);
}

void Balloon::move()
{
    setPos(x()+5, y()-15);
    if(pos().y()<-100){
        game->escape->reduction();
        scene()->removeItem(this);
        delete this;
    }
}

void Balloon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(event->button() == Qt::MouseButton::LeftButton){
        Explosion * explosion = new Explosion();
        explosion->setPos(x(), y());
        scene()->addItem(explosion);
    }
}

