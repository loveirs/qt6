#ifndef REGI_H
#define REGI_H

#include <QDialog>
class login;
namespace Ui {
class regi;
}

class regi : public QDialog
{
    Q_OBJECT

public:
    explicit regi(QWidget *parent = nullptr);
    ~regi();
    void set_login(const std::weak_ptr<login>&login);
    void slot_regi();
private:
    Ui::regi *ui;
    std::weak_ptr<login> _login;
};

#endif // REGI_H
