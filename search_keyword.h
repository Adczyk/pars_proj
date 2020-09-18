#ifndef SEARCH_KEYWORD_H
#define SEARCH_KEYWORD_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class search_keyword; }
QT_END_NAMESPACE

class search_keyword : public QDialog
{
    Q_OBJECT

public:
    explicit search_keyword(QWidget *parent = nullptr);
    ~search_keyword();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

public slots:
    QString getFindText_keywords();

private:
    Ui::search_keyword *ui;
private:
    QString findText_keywords;
};

#endif // SEARCH_KEYWORD_H
