#include "search_tag.h"
#include "ui_search_tag.h"
#include <QMessageBox>

search_tag::search_tag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search_tag)
{
    ui->setupUi(this);
}

search_tag::~search_tag()
{
    delete ui;
}

void search_tag::on_buttonBox_accepted()
{
    QString temp_string;

    temp_string = ui->lineEdit_2->text();
//    if(!temp_string.isEmpty())
//    {
        text_keyword = split_words(temp_string);
//    }

    temp_string = ui->lineEdit->text();
//    if(!temp_string.isEmpty())
//    {
        text_tag = split_words(temp_string);
//    }

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    hide();
}

QStringList search_tag::getFindText_tag()
{
    return text_tag;
}

QStringList search_tag::getFindText_tag_keyword()
{
    return text_keyword;
}

QStringList search_tag::split_words(QString temp_string)
{
    QStringList temp_list;
    temp_list.clear();
    temp_list = temp_string.split(";");
    return temp_list;
}

void search_tag::on_buttonBox_rejected()
{
    return;
}
