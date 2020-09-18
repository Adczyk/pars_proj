#include "open_save_file.h"
#include "form.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

open_save_file::open_save_file(QWidget *parent) : QMainWindow(parent)
{
}

QString& open_save_file::open_file()
{
    QString filter = "log file (*.log) ;; Text File (*.txt)";
    file_name = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath(), filter);
    QMessageBox::information(this,"..",file_name);
    QFile file(file_name);

    if (!file.open(QFile::ReadOnly | QFile::Text)) QMessageBox::warning(this,"title","file not open");
    else
    {
    QTextStream in(&file);
    text = in.readAll();
    }

    file.close();

    return text;
}

void open_save_file::save_file(QString& current_tab_text)
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

QString open_save_file::file_path()
{
    return file_name;
}
