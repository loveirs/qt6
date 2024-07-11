#ifndef MAIN_DIALOG_H
#define MAIN_DIALOG_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class main_dialog;
}
QT_END_NAMESPACE

class main_dialog : public QMainWindow
{
    Q_OBJECT

public:
    main_dialog(QWidget *parent = nullptr);
    ~main_dialog();

private slots:
    void on_enter_child_clicked();

private:
    Ui::main_dialog *ui;
};
#endif // MAIN_DIALOG_H
