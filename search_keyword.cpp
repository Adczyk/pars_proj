#include "search_keyword.h"
#include "ui_search_keyword.h"
#include <QMessageBox>

search_keyword::search_keyword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search_keyword)
{
    ui->setupUi(this);
    findText_keywords = "";
}

search_keyword::~search_keyword()
{
    delete ui;
}

void search_keyword::on_buttonBox_accepted()
{
    QString text = ui->lineEdit->text();

    if (text.isEmpty())
    {
        QMessageBox::information(this, tr("Empty Field"), tr("Please enter a keywords."));
        return;
    }
    else
    {
        findText_keywords = text;
        ui->lineEdit->clear();
        hide();
    }

}

QString search_keyword::getFindText_keywords()
{
    return findText_keywords;
}

void search_keyword::on_buttonBox_rejected()
{
    return;
}
