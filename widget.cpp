#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(3000, 2000);
    //this->
    //输出用户名，以及权限；
    this->display_userandrole();
    this->set_pushbutton();
    connect(add_new_btn, &QPushButton::clicked, this, &Widget::add_new);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::display_userandrole()
{
    QFont ft;
    ft.setPointSize(12);
    username_lab = new QLabel(this);
    username_lab->move(30,20);
    username_lab->setFont(ft);
    username_lab->setText("用户名:");
    username_real = new QLabel(this);
    username_real->move(120,20);
    username_real->setFont(ft);
    username_real->setText(q_username);
    userrole_lab = new QLabel(this);
    userrole_lab->move(200, 20);
    userrole_lab->setFont(ft);
    userrole_lab->setText("权限：");
    userrole_real = new QLabel(this);
    userrole_real->move(270, 20);
    userrole_real->setFont(ft);
    userrole_real->setText(q_role);
}

void Widget::set_pushbutton()
{
    QFont ft;
    ft.setPointSize(10);
    add_new_btn = new QPushButton(this);
    add_new_btn->move(30, 60);
    add_new_btn->setFont(ft);
    add_new_btn->setText("添加新项目");
}

void Widget::add_new()
{
    UserDB = new DataBase("userinfo.db");
    UserDB->DataBase_Connect();
    adn = new class add_new(this);
    if(adn->exec() == QDialog::Accepted)
    {

    }
}
