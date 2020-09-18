#ifndef SEARCH_TAG_H
#define SEARCH_TAG_H

#include <QDialog>

namespace Ui {
class search_tag;
}

class search_tag : public QDialog
{
    Q_OBJECT

public:
    explicit search_tag(QWidget *parent = nullptr);
    ~search_tag();

public:
    Ui::search_tag *ui;
    QStringList getFindText_tag();
    QStringList getFindText_tag_keyword();
    QStringList split_words(QString);
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    QStringList text_tag;
    QStringList text_keyword;
};

#endif // SEARCH_TAG_H
