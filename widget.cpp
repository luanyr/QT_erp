#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //输出用户名，以及权限；
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

Widget::~Widget()
{
    delete ui;
}

