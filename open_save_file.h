#ifndef OPEN_SAVE_FILE_H
#define OPEN_SAVE_FILE_H

#include <QMainWindow>


class open_save_file : public QMainWindow
{
    Q_OBJECT
public:
    explicit open_save_file(QWidget *parent = nullptr);
    QString& open_file();
    QString file_path();
    void save_file(QString& current_tab_text);

private:
    QString text ="";
    QString file_name ="";

};

#endif // OPEN_SAVE_FILE_H
