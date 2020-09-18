#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

public slots:
    void text_to_plain(QString& text);
    QString get_text_from_plain();
    void refresh_plains(QString& text);
    void SetText(QString text);

private:
    Ui::Form *ui;
};

#endif // FORM_H
