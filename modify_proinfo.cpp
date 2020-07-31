#include "modify_proinfo.h"
#include "ui_modify_proinfo.h"

modify_proinfo::modify_proinfo(QWidget *parent) :
    add_proinfo(parent),
    ui(new Ui::modify_proinfo)
{
    ui->setupUi(this);
    this->set_format();
}

modify_proinfo::~modify_proinfo()
{
    delete ui;
}
