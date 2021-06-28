#include "Duration.h"
#include <QFont>
#include <QThread>
#include <QMessageBox>
#include <QTime>
#include <QCoreApplication>


Duration::Duration(QGraphicsItem *parent): QGraphicsTextItem(parent){
    duration = 60;

    setPlainText(QString("Remaining Time: ") + QString::number(duration));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",15));
}

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

}

void Duration::reduction(){
    for(duration = 60; duration>=0; duration--){
        delay();
        setPlainText(QString("Remaining Time: ") + QString::number(duration));

        if(duration==0){
            QMessageBox msgBox;
            msgBox.setStyleSheet("QLabel{min-width:320px; font-size:20px; color:red;} QPushButton{ width:150px; font-size:16px;}");
            msgBox.setText("GAME OVER");
            msgBox.setInformativeText("Good game.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            setPlainText(QString("Remaining Time: ") + "0");
            int ret = msgBox.exec();
            switch (ret) {
              case QMessageBox::Ok:
                exit(duration);
            }
        }
    }
}

int Duration::getDuration(){
    return duration;
}
