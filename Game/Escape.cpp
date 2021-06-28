#include "Escape.h"
#include <QFont>

Escape::Escape(QGraphicsItem *parent): QGraphicsTextItem(parent){
    escape = 0;

    setPlainText(QString("Amount of Escaping Balloons: ") + QString::number(escape));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times", 16));
}

void Escape::reduction(){
    escape++;
    setPlainText(QString("Amount of Escaping Balloons: ") + QString::number(escape));
}

int Escape::getEscapes(){
    return escape;
}
