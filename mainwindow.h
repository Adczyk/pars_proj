#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_open_file_clicked();
    void on_search_keyword_clicked();
    void on_search_tag_clicked();
    void on_tabWidget_tabCloseRequested(int index);
    QString& get_text();

public:
    Ui::MainWindow *ui;

private slots:
    void show_tab(QString keywords, Form *f);
    void on_actionOpen_file_triggered();
    void on_actionShow_text_file_triggered();
    void on_actionSave_file_triggered();

private:
    QString text;
    QString file_path;
    QString fileName;
};
#endif // MAINWINDOW_H
