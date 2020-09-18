#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::text_to_plain(QString& text)
{
    ui->plainTextEdit->setPlainText(text);
}

QString Form::get_text_from_plain()
{
    return ui->plainTextEdit->toPlainText();
}

void Form::refresh_plains(QString& text)
{
     ui->plainTextEdit->setPlainText(text);
}

void Form::SetText(QString text)
{
    ui->plainTextEdit->setPlainText(text);
}
