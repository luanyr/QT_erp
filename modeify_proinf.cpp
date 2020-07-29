#include "modeify_proinf.h"
#include "ui_modeify_proinf.h"

modeify_proinf::modeify_proinf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modeify_proinf)
{
    ui->setupUi(this);
}

modeify_proinf::~modeify_proinf()
{
    delete ui;
}
