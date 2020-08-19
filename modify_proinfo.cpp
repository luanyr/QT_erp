#include "modify_proinfo.h"
#include "ui_modify_proinfo.h"

modify_proinfo::modify_proinfo(pro_format modify_info) :
    add_proinfo(),
    ui(new Ui::modify_proinfo)
{
    ui->setupUi(this);
    this->modify_setformat();
    this->pro_no_lEd->setReadOnly(true);
    this->mdy_prono = modify_info.get_prono();
    this->mdy_proentertime = modify_info.get_entertime();
    this->mdy_proouttime = modify_info.get_outtime();
    this->mdy_prostatus = modify_info.get_prostatus();
    this->mdy_pronote = modify_info.get_pronote();
    this->mdy_filename = modify_info.get_logname();
    set_modifycontent();
    connect(confirm_btn, &QPushButton::clicked, this, &modify_proinfo::enable_push);
    connect(push_btn, &QPushButton::clicked, this, &modify_proinfo::push2db);
    connect(select_file_btn, &QPushButton::clicked, this, &modify_proinfo::select_save_file);
    connect(delete_btn, &QPushButton::clicked, this, &modify_proinfo::delete_warning);
    connect(this, &modify_proinfo::confirm_delete, this, &modify_proinfo::delete_proinfo);
}

modify_proinfo::~modify_proinfo()
{
    delete ui;
}

void modify_proinfo::modify_setformat()
{
    this->set_format();
    this->delete_btn = new QPushButton(this);
    this->delete_btn->setFont(ft);
    this->delete_btn->move(450, 350);
    this->delete_btn->resize(120, 30);
    this->delete_btn->setText("删除");
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

void modify_proinfo::push2db()
{
        push_no = this->pro_no_lEd->text();
        QDate entertime = this->pro_enter_de->date();
        push_entertime = entertime.toString("yyyy-MM-dd");
        QDate outtime = this->pro_out_de->date();
        push_outtime = outtime.toString("yyyy-MM-dd");
        push_status = this->pro_status_cbx->currentText();
        push_note = this->pro_note_tEt->toPlainText();
        QString tabname = this->pro_name_cbx->currentText();
        new_pro_info = new pro_format(push_no, push_entertime, push_outtime, push_status, push_note, log_filename, file_conten);
        UserDB = new DataBase("Production.db");
        UserDB->DataBase_Connect();
        if(UserDB->DataBase_modify(tabname, push_no, *new_pro_info) == true) {
            QMessageBox::information(this, "通知", "修改成功");
        } else {
            QMessageBox::information(this, "通知", "修改失败");
        }
}

void modify_proinfo::delete_warning()
{
    if(QMessageBox::warning(this, "警告", "确认需要删除!",QMessageBox::Yes|QMessageBox::No)) {
        emit confirm_delete();
    } else {
        emit cancel_delete();
    }

}

void modify_proinfo::delete_proinfo()
{
    mdy_prono = this->pro_no_lEd->text();
    QString tabname = this->pro_name_cbx->currentText();
    UserDB = new DataBase("Production.db");
    UserDB->DataBase_Connect();
    if(UserDB->DataBase_delete(tabname, mdy_prono) == true) {
        QMessageBox::information(this, "通知", "删除成功");
    } else {
        QMessageBox::information(this, "通知", "删除失败");
    }
}
