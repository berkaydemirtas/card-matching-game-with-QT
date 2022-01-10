#ifndef COLORBUTTON_H
#define COLORBUTTON_H
#include <QPushButton>
#include <QPalette>
#include <QLabel>
#include "mygridlayout.h"
#include <QGridLayout>
class colorbutton :public QPushButton
{

    Q_OBJECT
public:
    colorbutton(const QString& color,const QString& text, QWidget* parent=0, const QString& str="");
    QString color;
    QString text;
    int counter;
    QString str;
    QLabel *lab;

public slots:
    void change_card_space();
    void change_card();
    void change_card_qm();
};

#endif // COLORBUTTON_H
