#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include "file_operation.h"

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QWidget *parent =0);
    void run(file_operation *file);
    bool Stop;
};

#endif // MYTHREAD_H
