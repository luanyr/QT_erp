#include "login.h"
#include "ui_login.h"
#include "user_format.h"
QString q_username;
QString q_role;
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("登录界面");

    //标题label
    QFont title_ft;
    title_ft.setPointSize(15);
    title_lab = new QLabel(this);
    title_lab->move(70, 20);
    title_lab->setFont(title_ft);
    title_lab->setText("产品服务平台");
    //用户名label
    QFont ft;
    ft.setPointSize(13);
    username_lab = new QLabel(this);
    username_lab->move(70, 80);
    username_lab->setFont(ft);
    username_lab->setText("用户名: ");
    //密码label
    password_lab = new QLabel(this);
    password_lab->move(80, 130);
    password_lab->setFont(ft);
    password_lab->setText("密码:");
    //用户名lineedit
    username_lEd = new QLineEdit(this);
    username_lEd->move(160, 80);
    //密码lineedite
    password_lEd = new QLineEdit(this);
    password_lEd->move(160, 130);
    password_lEd->setEchoMode(QLineEdit::Password);
    //登录button
    login_btn = new QPushButton(this);
    login_btn->setText("登录");
    login_btn->move(80, 200);
    //创建用户info
    user_info user_admin("luan", "password", "admin");
    //创建用户资料数据库
    UserDB = new DataBase("userinfo.db");
    UserDB->DataBase_Connect();
    UserDB->DataBase_createTab(QString("userinfo"), 0);
    connect(login_btn, &QPushButton::clicked, this, &login::user_login);
}

void login::user_login()
{
    QString username = this->username_lEd->text().toLatin1();
    QString password = this->password_lEd->text().toLatin1();
    if(verify_useraccount(username, password))
    {
        UserDB->DataBase_displayTab("userinfo");
        q_username = username;
        q_role = get_userrole(username);
        qDebug() << "role" << q_role << endl;
        accept();
    } else {
        QMessageBox::warning(this, "Warning", "用户名或密码错误");
    }
}

bool login::verify_useraccount(QString username, QString password)
{
    if(UserDB->DataBase_SelectTab("userinfo", "username", username, "password") == password)
    {
        return true;
    } else {
        return false;
    }
}

QString login::get_userrole(QString username)
{
    return UserDB->DataBase_SelectTab("userinfo", "username", username, "role");
}

login::~login()
{
    delete ui;
}
