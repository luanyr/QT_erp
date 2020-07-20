#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include "database.h"
#include <QString>
extern QString q_username;
extern QString q_role;
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT
public:
    friend class Widget;
    explicit login(QWidget *parent = nullptr);
    ~login();
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
    bool verify_useraccount(QString username, QString password);
    QString get_userrole(QString username);
    DataBase *UserDB;
};


#endif // LOGIN_H
