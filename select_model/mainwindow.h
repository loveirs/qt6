#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTableView>

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

private:
    Ui::MainWindow *ui;
    QTableView *table_view;

private slots:
    void get_current_item();
    void toggle_selection();
    void up_data_selection(QItemSelection selected, QItemSelection deselected);
    void change_current(QModelIndex current, QModelIndex previous);

};
#endif // MAINWINDOW_H
