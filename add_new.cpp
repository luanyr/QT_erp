#include "add_new.h"
#include "ui_add_new.h"

add_new::add_new(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_new)
{
    ui->setupUi(this);
}

add_new::~add_new()
{
    delete ui;
}
