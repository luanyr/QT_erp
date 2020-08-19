#include "log_dia.h"
#include "ui_log_dia.h"

log_dia::log_dia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::log_dia)
{
    ui->setupUi(this);
    set_format();
    connect(exit_btn, &QPushButton::clicked, this, &QDialog::close);
}

log_dia::~log_dia()
{
    delete ui;
}

void log_dia::set_format()
{
    this->setWindowTitle("查看记录");
    QFont ft;
    ft.setPointSize(12);
    this->log_TEt = new QTextEdit(this);
    log_TEt->setFont(ft);
    log_TEt->resize(300,200);
    log_TEt->move(45,30);

    this->exit_btn = new QPushButton(this);
    exit_btn->setFont(ft);
    exit_btn->resize(100, 30);
    exit_btn->move(130, 250);
    exit_btn->setText("退出");
}


void log_dia::set_log(QByteArray Qba_log)
{

    this->log_TEt->setText(Qba_log);
    this->log_TEt->setReadOnly(true);
}

void log_dia::set_note(QString Qstr_note)
{
    this->log_TEt->setText(Qstr_note);
    this->log_TEt->setReadOnly(true);
}
