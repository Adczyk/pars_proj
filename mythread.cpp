#include "mythread.h"
#include "file_operation.h"
#include <QtCore>

MyThread::MyThread(QWidget *parent) : QThread(parent)
{

}

void MyThread::run(file_operation *file)
{
    file->open_file();
}
