#include "mytimer.h"
#include <QTimer>
#include <QEventLoop>


mytimer::mytimer(): QObject()
{
    QEventLoop loop;
        QTimer::singleShot(100, &loop, &QEventLoop::quit);
         loop.exec();
    timer=new QTimer();
    label=new QLabel("Time (secs):0");
    counter=0;
    //counter+=1;
    //label->setText("Time (secs): "+QString::number(this->counter));
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(mytimerSlot()));
    timer->start(1000);
}

//it increase counter by 1 for every 1000ms. Object of this class is used as an clock
void mytimer::mytimerSlot(){
    counter+=1;
    label->setText("Time (secs): "+QString::number(this->counter));
    if(this->counter>=180){
        this->timer->stop();
        QMessageBox *mb= new QMessageBox();
        mb->setText("YOU FAILED!");
        mb->setStandardButtons(QMessageBox::Cancel);
        mb->exec();
    }
}
//it is used in new game condition and restart all fields.
void mytimer::restart(){
    this->label->setText("Time (secs):0");
    this->counter=0;
}
