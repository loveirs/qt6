#ifndef CHILD_DIALOG_H
#define CHILD_DIALOG_H

#include <QDialog>

namespace Ui {
class child_dialog;
}

class child_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit child_dialog(QWidget *parent = nullptr);
    ~child_dialog();

private slots:
    void on_enter_nain_window_clicked();

private:
    Ui::child_dialog *ui;
};

#endif // CHILD_DIALOG_H
