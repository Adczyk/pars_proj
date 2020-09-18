#include "search_func.h"
#include <QTextStream>
#include <QMessageBox>

search_func::search_func()
{

}

QVector<QString> search_func::find_logs_keywords(QString keywords, QString& text)
{
        QVector<QString> find_line;
        QStringList keywords_list = keywords.split(";");
        QTextStream stream(&text);
        while(!stream.atEnd())
        {
            QString line = stream.readLine();
            for(int i=0; i<keywords_list.size();i++)
            {
                int pos = line.indexOf(keywords_list[i], 0,Qt::CaseInsensitive);
                if (pos >= 0)
                {
                    find_line.push_back(line);
                }
            }
        }
        stream.seek(0);
        return find_line;

}

QVector<QString> search_func::find_logs_tags(QStringList& tags, QStringList& keywords, QString& text)
{  
    QVector<QString> find_line;
    QTextStream stream(&text);
    while(!stream.atEnd())
    {
        QString line = stream.readLine();
        for(int i=0; i<tags.size();i++)
        {
            int pos1 = line.indexOf(tags[i], 0,Qt::CaseInsensitive);
            if (pos1 >= 0)
            {
                for(int j=0; j<keywords.size(); j++)
                {
                    int pos2 = line.indexOf(keywords[j], 0,Qt::CaseInsensitive);
                    if (pos2 >= 0)
                    {
                    find_line.push_back(line);
                    break;
                    }
                }
             }
        }
    }
    stream.seek(0);
    return find_line;

}

QString search_func::string_concatenation(QStringList tags, QStringList keywords)
{
    QString tab_view;
    for (int i=0; i<tags.size(); i++)
    {
        tab_view += "[" + tags[i] + "]" + ";";
    }
    tab_view += " ";
    for(int j=0; j<keywords.size(); j++)
    {
        tab_view += keywords[j] + ";";
    }
    return tab_view;
}

search_func::~search_func()
{

}
