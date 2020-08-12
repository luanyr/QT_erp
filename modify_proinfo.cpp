#include "modify_proinfo.h"
#include "ui_modify_proinfo.h"

modify_proinfo::modify_proinfo(pro_format modify_info) :
    add_proinfo(),
    ui(new Ui::modify_proinfo)
{
    ui->setupUi(this);
    this->set_format();
    this->mdy_prono = modify_info.get_prono();
    this->mdy_proentertime = modify_info.get_entertime();
    this->mdy_proouttime = modify_info.get_outtime();
    this->mdy_prostatus = modify_info.get_prostatus();
    this->mdy_pronote = modify_info.get_pronote();
    this->mdy_filename = modify_info.get_logname();
    qDebug() << this->mdy_prono << endl;
    set_modifycontent();
}

modify_proinfo::~modify_proinfo()
{
    delete ui;
}

void modify_proinfo::set_modifycontent()
{
    this->pro_no_lEd->setText(mdy_prono);
    QDate entertime = QDate::fromString(mdy_proentertime,"yyyy-MM-dd");
    this->pro_enter_de->setDate(entertime);
    QDate outtime = QDate::fromString(mdy_proouttime, "yyyy-MM-dd");
    this->pro_out_de->setDate(outtime);
    if(this->mdy_prostatus == "待测试")
        this->pro_status_cbx->setCurrentIndex(0);
    else if(this->mdy_prostatus == "已测试")
        this->pro_status_cbx->setCurrentIndex(1);
    else
        this->pro_status_cbx->setCurrentIndex(2);
    this->pro_note_tEt->setText(mdy_pronote);
    this->file_path_lEd->setText(mdy_filename);
}
