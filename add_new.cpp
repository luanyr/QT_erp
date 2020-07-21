#include "add_new.h"
#include "ui_add_new.h"

add_new::add_new(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_new)
{
    ui->setupUi(this);
    set_format();
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
    Proname_Lab->move(30, 20);
    Proname_Lab->setFont(ft);
    Proname_Lab->setText("产品名：");
}
