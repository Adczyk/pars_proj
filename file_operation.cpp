#include "file_operation.h"
#include "mythread.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

file_operation::file_operation(QWidget *parent) : QMainWindow(parent)
{
}

void file_operation::open_file()
{
    QString filter = "log file (*.log) ;; Text File (*.txt)";
    path = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath(), filter);
    QFile file(path);

    if (!file.open(QFile::ReadOnly | QFile::Text) && !path.isNull()) QMessageBox::warning(this,"title","file not open");

    else if(!path.isNull())
    {
        file_name = path;
        QMessageBox::information(this,"..",path);
        FileName = file.fileName();
        FileName = FileName.section("/",-1,-1);
        QTextStream in(&file);
        text = in.readAll();
        file.close();
    }
    else
    {
        return;
    }

}

void file_operation::save_file(QString& current_tab_text)
{
    QString filter = "log file (*.log) ;; Text File (*.txt)";
    QString save_file_name = QFileDialog::getSaveFileName(this, "Write a file. You can save current tab", QDir::homePath(), filter);
    QFile file(save_file_name);

    if (!file.open(QFile::WriteOnly | QFile::Text)) QMessageBox::warning(this,"title","file not saved");
    else
    {
    QTextStream out(&file);
    out << current_tab_text;
    }
    file.flush();
    file.close();
}

QString file_operation::file_path()
{
    return file_name;
}

QString& file_operation::get_text()
{
    return text;
}

QString file_operation::getFileName()
{
    return FileName;
}

file_operation::~file_operation()
{
 ;
}
