#ifndef file_operation_H
#define file_operation_H

#include <QMainWindow>


class file_operation : public QMainWindow
{
    Q_OBJECT
public:
    explicit file_operation(QWidget *parent = nullptr);
    ~file_operation();
    void open_file();
    QString file_path();
    QString& get_text();
    void save_file(QString& current_tab_text);
    QString getFileName();

private:
    QString text;
    QString file_name;
    QString path;
    QString FileName;

};

#endif // file_operation_H
