#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class login;
}
QT_END_NAMESPACE
class regi;
class login : public QDialog,public std::enable_shared_from_this<login>
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();
    void init_signal();
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::login *ui;
    std::shared_ptr<regi> _regi;
};
#endif // LOGIN_H
