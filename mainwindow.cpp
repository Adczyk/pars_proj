#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "search_keyword.h"
#include "search_tag.h"
#include "form.h"
#include "search_func.h"
#include "file_operation.h"
#include "mythread.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->removeTab(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_file_clicked()
{
    QString temp_text, path;
    file_operation *file = new file_operation(this);
    MyThread *mthread = new MyThread(this);
    mthread->run(file);
    //file->open_file();
    temp_text = file->get_text();
    path = file->file_path();
    if (temp_text != "")
    {
        file_path = path;
        text = temp_text;
        fileName = file->getFileName();
        ui->lineEdit->setPlaceholderText(file_path);
        on_actionShow_text_file_triggered();
    }
}

void MainWindow::on_search_keyword_clicked()
{
    search_keyword Search_Keyword;
    Search_Keyword.setModal(true);
    Search_Keyword.exec();

    QVector<QString> find_lines_index;
    QString keywords = Search_Keyword.getFindText_keywords();
    if (keywords != "")
    {
        search_func ser_fn;
        QString str;
        Form *Fr = new Form(this);
        show_tab(keywords, Fr);
        find_lines_index = ser_fn.find_logs_keywords(keywords, text);
        for (int i=0; i<find_lines_index.size(); i++)
        {
            if(i>0) str+= "\n";
            str += find_lines_index[i];
        }
        Fr->text_to_plain(str);
    }

}

void MainWindow::on_search_tag_clicked()
{
    search_tag Search_Tag;
    Search_Tag.setModal(true);
    Search_Tag.exec();

    QVector<QString> find_lines_index;
    QStringList tags = Search_Tag.getFindText_tag();
    QStringList keyword_to_tag = Search_Tag.getFindText_tag_keyword();
    QString str;

    if (!tags.isEmpty())
    {
        search_func ser_fn;
        QString tab_view = "";

        tab_view = ser_fn.string_concatenation(tags, keyword_to_tag);

        Form *Fr = new Form(this);
        find_lines_index = ser_fn.find_logs_tags(tags, keyword_to_tag, text);

        for (int i=0; i<find_lines_index.size(); i++)
        {
           if(i>0) str+= "\n";
           str += find_lines_index[i];
        }

        show_tab(tab_view, Fr);
        Fr->text_to_plain(str);
    }
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

void MainWindow::show_tab(QString keywords, Form *f)
{
    ui->tabWidget->addTab(f, QString("%1").arg(keywords));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
    ui->tabWidget->setTabText((ui->tabWidget->count()-1),keywords);
}

void MainWindow::on_actionOpen_file_triggered()
{
    on_open_file_clicked();
}

void MainWindow::on_actionShow_text_file_triggered()
{
    Form *Fr = new Form(this);
    show_tab(fileName, Fr);
    Fr->text_to_plain(text);
}

void MainWindow::on_actionSave_file_triggered()
{
   if(file_path != "" && text != "")
   {
   int currentIndex = ui->tabWidget->currentIndex();
   QMessageBox::information(this,"title","You will save current tab");
   QString current_tab_text = static_cast<Form*>(ui->tabWidget->widget(currentIndex))->get_text_from_plain();
   file_operation file_operation;
   file_operation.save_file(current_tab_text);
   }
   else
   {
     QMessageBox::information(this,"info","Please upload the file first or do a log search ");
   }
}

QString& MainWindow::get_text()
{
    return text;
}
