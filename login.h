#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include "database.h"
#include <QString>
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    bool verify_useraccount();
    QString username;
public slots:
    void user_login();
private:
    Ui::login *ui;
    QLabel *title_lab;
    QLabel *username_lab;
    QLabel *password_lab;
    QLineEdit *username_lEd;
    QLineEdit *password_lEd;
    QPushButton *login_btn;
    DataBase *UserDB;

};


#endif // LOGIN_H
