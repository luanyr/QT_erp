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
    username_real->move(50,20);
    username_real->setFont(ft);

}

Widget::~Widget()
{
    delete ui;
}

