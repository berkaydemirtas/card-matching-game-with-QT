#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "myTimer.h"
#include "colorbutton.h"
#include <QThread>
#include "newgame.h"

int main(int argc, char *argv[])
{

    QApplication app(argc,argv);
    QWidget *wid = new QWidget();
    QHBoxLayout *vb= new QHBoxLayout();
    QVBoxLayout *vbv= new QVBoxLayout();
    mytimer mt;
    myGridLayout *gl = new myGridLayout(mt.timer,mt.counter);
    QList<QString> list = { "a","b","c","d","e","f","g","h","i","k","l","m","n","p","z","a","b","c","d","e","f","g","h","i","k","l","m","n","p","z" };

    //in this section, a grid is created from list of strings randomly
    for(int row=0; row<5; row++){
        for(int col=0; col<6; col++){
            int a=rand()%list.size();
            QString b=list[a];
            list.removeAt(a);
            colorbutton *randButton = new colorbutton("cyan", "?",0,b);
            QObject::connect(randButton, SIGNAL(clicked()),
                             gl, SLOT(change_cards()));
            QObject::connect(randButton, SIGNAL(clicked()),
                             gl, SLOT(finish()));
            gl->addWidget(randButton, row, col, 1, 1);
        }
    }

    //these are quit and new game button
    QPushButton *quit = new QPushButton;
    QObject::connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
    quit->setText("Quit");

    QPushButton *newgame = new QPushButton;
    QObject::connect(newgame,SIGNAL(clicked()),gl,SLOT(restart()));
    QObject::connect(newgame,SIGNAL(clicked()),&mt,SLOT(restart()));
    newgame->setText("New Game");

    //the structure of widgets and layouts is drawed in documentation
    vb->addWidget(mt.label);
    vb->addWidget(gl->lab);
    vb->addWidget(newgame);
    vb->addWidget(quit);
    vbv->addLayout(vb);
    vbv->addLayout(gl);
    wid->setLayout(vbv);
    wid->resize(700,250);
    wid->setWindowTitle("Card Match Game");
    wid->show();
    return app.exec();
}
