#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QDialog>
#include <QMainWindow>
#include<QLineEdit>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void show_text_frame();
    void show_text_block();
    void set_text_font(bool);
    void insert_table();
    void insert_list();
    void insert_image();
    void text_find();
    void find_next();


private:
    Ui::MainWindow *ui;
    QDialog *find_dialog;
    QLineEdit * line_dialog;

};
#endif // MAINWINDOW_H
