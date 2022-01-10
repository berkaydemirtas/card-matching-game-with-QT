#include "mygridlayout.h"
#include "mytimer.h"
#include <QThread>
#include <QEventLoop>
myGridLayout::myGridLayout(QTimer *timer,int& count):QGridLayout()
{
    this->timer=timer;
    counter=0;
    counter2=0;
    counter3=0;
    lab=new QLabel("Score:0");

    QObject::connect(this->timer,SIGNAL(timeout()),this,SLOT(stopp()));
    timer->start(1000);
}


//this function goes over the grid and checks if the player win
bool myGridLayout::finish(){
    QString myStr="";
    bool fin=true;
    for(int i=0;i<this->count();i++){
        colorbutton *cb=qobject_cast<colorbutton*>(this->itemAt(i)->widget());

        if(cb->text=="?"){
            fin=false;
            break;
        }
    }

    //if player win, the buttons are disabled, timer is stopped and a message box is appear
    if(fin){
        this->timer->stop();
        for(int i=0;i<this->count();i++){
            colorbutton *cb=qobject_cast<colorbutton*>(this->itemAt(i)->widget());
            cb->setEnabled(false);
            }
        QMessageBox *mb= new QMessageBox();
        mb->setText("YOU WON!");
        mb->setStandardButtons(QMessageBox::Cancel);
        mb->exec();
    }
}

//first it traverse over the grid and finds the number of open cards and their location
//then by using the slots in collorbutton, sets the cards and checks if there are an open
//pair.
void myGridLayout::change_cards(){

    bool pair=false;
    int j=-1;
    int k=-1;
    QString myStr1="1";
    QString myStr2="2";
    for(int i=0;i<this->count();i++){
        colorbutton *cb2=qobject_cast<colorbutton*>(this->itemAt(i)->widget());
        if(cb2->text=="?" || cb2->text=="")
            continue;
        else if(j==-1){
            j=i;
            myStr1=cb2->text;
        }
        else{
            k=i;
            myStr2=cb2->text;
            pair=true;
        }
    }

    //pair condition
    if(myStr1==myStr2){
        colorbutton *cb3=qobject_cast<colorbutton*>(this->itemAt(k)->widget());
        colorbutton *cb4=qobject_cast<colorbutton*>(this->itemAt(j)->widget());
        cb3->change_card();
        cb4->change_card();
        QEventLoop loop;
            QTimer::singleShot(500, &loop, &QEventLoop::quit);
             loop.exec();
        cb3->change_card_space();
        cb4->change_card_space();
        displayScore();
    }
    //2 open card but not pair condition
    else if(pair){
        colorbutton *cb3=qobject_cast<colorbutton*>(this->itemAt(k)->widget());
        colorbutton *cb4=qobject_cast<colorbutton*>(this->itemAt(j)->widget());
        cb3->change_card();
        cb4->change_card();
        QEventLoop loop;
            QTimer::singleShot(600, &loop, &QEventLoop::quit);
             loop.exec();
        cb3->change_card_qm();
        cb4->change_card_qm();
    }


}
void myGridLayout::displayScore(){
    counter+=1;
    lab->setText("Score: "+QString::number(this->counter));
}

//this slots disabled the buttons if the time is over
void myGridLayout::stopp(){
    counter2+=1;
    counter3=counter2;
   // lab2->setText("Time (secs): "+QString::number(this->counter3));
    if(counter2>=180){
        for(int i=0;i<this->count();i++){
            colorbutton *cb=qobject_cast<colorbutton*>(this->itemAt(i)->widget());
            cb->setEnabled(false);
            }

    }

}

//it restarts all fields of this class and colorbutton if there is new game click.
void myGridLayout::restart(){
    for(int i=0;i<this->count();i++){
        colorbutton *cb=qobject_cast<colorbutton*>(this->itemAt(i)->widget());
        cb->setEnabled(true);
        cb->text="?";
        cb->setText("?");
        }
    this->lab->setText("Score: 0");
    this->counter=0;
    this->counter2=0;
}



