#ifndef MYTIMER_H
#define MYTIMER_H
#include <QTimer>
#include <QLabel>
#include <QMessageBox>

class mytimer : public QObject
{
Q_OBJECT

public:
    mytimer();
    QTimer *timer;
    QLabel *label;
    int counter;
public slots:
  void mytimerSlot();
  void restart();
};

#endif // MYTIMER_H
