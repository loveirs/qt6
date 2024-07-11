#ifndef CHILDDIALOG_H
#define CHILDDIALOG_H

#include <QDialog>

namespace Ui {
class childdialog;
}

class childdialog : public QDialog
{
    Q_OBJECT
signals:
    void show_main_sig();
public:
    explicit childdialog(QWidget *parent = nullptr);
    ~childdialog();
public slots:
    void show_main_window();

private:
    Ui::childdialog *ui;
    QWidget* _parent;
};

#endif // CHILDDIALOG_H
