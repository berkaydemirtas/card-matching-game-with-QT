#ifndef MYGRIDLAYOUT_H
#define MYGRIDLAYOUT_H
#include <QGridLayout>
#include <QTimer>
#include <QMessageBox>
#include <QLabel>
#include "colorbutton.h"
#include "myTimer.h"

class myGridLayout : public QGridLayout
{
    Q_OBJECT
public:
    myGridLayout(QTimer* timer,int& counter);
    QTimer *timer;
    QLabel *lab;
    QLabel *lab2;
    int counter;
    int counter2;
    int counter3;
public slots:
    bool finish();
    void change_cards();
    void displayScore();
    void stopp();
    void restart();

};

#endif // MYGRIDLAYOUT_H
