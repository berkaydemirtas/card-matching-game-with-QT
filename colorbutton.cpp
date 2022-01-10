#include "colorbutton.h"
#include <QThread>

//objects of this class are the buttons of grid.
colorbutton::colorbutton(const QString& color,const QString& text, QWidget* parent, const QString& str):
    QPushButton(text,parent)

{
    counter=0;
    lab=new QLabel("Score:0");
    this->str=str;
    this->color=color;
    this->text="?";
    QPalette pal = palette();
    pal.setColor(QPalette::Button, QColor(Qt::cyan));
    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    update();


    QObject::connect(this, SIGNAL(clicked()),this, SLOT(change_card()));
}


//changes the text of card to ""
void colorbutton::change_card_space(){
    this->setText("");
    this->text="";
}

//changes the text of card to string that it holds
void colorbutton::change_card(){
    if(this->text!=""){
    this->setText(this->str);
    this->text=str;
    }
}

//changes the text of card to "?"
void colorbutton::change_card_qm(){
    this->setText("?");
    this->text="?";
}




