#include "add_new.h"
#include "ui_add_new.h"

add_new::add_new(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_new)
{
    ui->setupUi(this);
    set_format();
    connect(add_btn, &QPushButton::clicked, this, &add_new::add2DB);
    connect(cancel_btn, &QPushButton::clicked, this, &add_new::close);
}

add_new::~add_new()
{
    delete ui;
}

void add_new::set_format()
{
    QFont ft;
    ft.setPointSize(12);
    Proname_Lab = new QLabel(this);
    Proname_Lab->move(10, 20);
    Proname_Lab->setFont(ft);
    Proname_Lab->setText("产品名：");
    Proname_LEd = new QLineEdit(this);
    Proname_LEd->setFont(ft);
    Proname_LEd->resize(130,30);
    Proname_LEd->move(120,20);
    add_btn = new QPushButton(this);
    add_btn->move(10,100);
    add_btn->setFont(ft);
    add_btn->setText("添加");
    cancel_btn = new QPushButton(this);
    cancel_btn->move(150,100);
    cancel_btn->setFont(ft);
    cancel_btn->setText("取消");
}

void add_new::add2DB()
{
    QString pro_name = this->Proname_LEd->text().toLatin1();
    UserDB = new DataBase("Production.db");
    UserDB->DataBase_Connect();
    if(UserDB->DataBase_IsTabExist(pro_name))
    {
        QMessageBox::warning(this, "错误", "该产品已存在！");
    } else {
        UserDB->DataBase_createTab(pro_name, 1);
        QMessageBox::information(this, "完成", "产品创建成功");
        accept();
    }
    UserDB->DataBase_Close();
}
