#ifndef SEARCH_FUNC_H
#define SEARCH_FUNC_H
#include <QLabel>
#include <QVector>

class search_func : public QLabel
{
   // Q_OBJECT
public:
    search_func();
    ~search_func();
    QVector<QString> find_logs_keywords(QString keywords, QString& text);
    QVector<QString> find_logs_tags(QStringList& tags, QStringList& tags2, QString& text);
    QString string_concatenation(QStringList tags, QStringList keywords);
};

#endif // SEARCH_FUNC_H
