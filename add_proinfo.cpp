#include "add_proinfo.h"
#include "ui_add_proinfo.h"

add_proinfo::add_proinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_proinfo)
{
    ui->setupUi(this);
    this->set_format();
    UserDB = new DataBase("Production.db");
    UserDB->DataBase_Connect();
    connect(confirm_btn, &QPushButton::clicked, this, &add_proinfo::enable_push);
}

add_proinfo::~add_proinfo()
{
    UserDB->DataBase_Close();
    delete ui;
}

void add_proinfo::set_format()
{
    QDate current_date = QDate::currentDate();
    QFont ft;
    ft.setPointSize(12);
    pro_no_lab = new QLabel(this);
    pro_no_lab->move(10, 20);
    pro_no_lab->setFont(ft);
    pro_no_lab->setText(QString("板号"));
    pro_entertime_lab = new QLabel(this);
    pro_entertime_lab->move(210, 20);
    pro_entertime_lab->setFont(ft);
    pro_entertime_lab->setText(QString("进入时间"));
    pro_outtime_lab = new QLabel(this);
    pro_outtime_lab->move(10, 120);
    pro_outtime_lab->setFont(ft);
    pro_outtime_lab->setText(QString("离开时间"));
    pro_status_lab = new QLabel(this);
    pro_status_lab->move(210, 120);
    pro_status_lab->setFont(ft);
    pro_status_lab->setText(QString("状态"));
    pro_note_lab = new QLabel(this);
    pro_note_lab->move(10, 220);
    pro_note_lab->setFont(ft);
    pro_note_lab->setText(QString("备注"));
    pro_no_lEd = new QLineEdit(this);
    pro_no_lEd->move(10, 50);
    pro_no_lEd->resize(80, 20);
    pro_enter_de = new QDateEdit(this);
    pro_enter_de->move(210, 50);
    pro_enter_de->setDate(current_date);
    pro_out_de = new QDateEdit(this);
    pro_out_de->move(10, 150);
    pro_out_de->setDate(current_date);

    pro_status_cbx = new QComboBox(this);
    pro_status_cbx->move(210, 150);
    pro_status_cbx->addItem("待测试");
    pro_status_cbx->addItem("已测试");
    pro_status_cbx->addItem("测试出错");
    pro_note_tEt = new QTextEdit(this);
    pro_note_tEt->move(60, 220);
    pro_note_tEt->resize(100,50);
    confirm_btn = new QPushButton(this);
    confirm_btn->move(210, 220);
    confirm_btn->setFont(ft);
    confirm_btn->setText("请确认信息");
    push_btn = new QPushButton(this);
    push_btn->move(210, 250);
    push_btn->setFont(ft);
    push_btn->setText("提交");
    push_btn->setDisabled(true);
    pro_name_cbx = new QComboBox(this);
    pro_name_cbx->move(10, 300);
    QStringList tablist = UserDB->DataBase_GetAllTab();
    bool val = tablist.contains("sqlite_sequence");
    if(val == true)
    {
        tablist.removeOne("sqlite_sequence");
    }
    QStringListIterator tabitr(tablist);
    while(tabitr.hasNext())
    {
        QString tabname = tabitr.next().toLocal8Bit();
        pro_name_cbx->addItem(tabname);
    }
}

void add_proinfo::enable_push()
{
    this->push_btn->setEnabled(true);
}

void add_proinfo::push2db()
{

    if(!this->pro_no_lEd->text().isEmpty())
    {
        push_no = this->pro_no_lEd->text();
        QDate entertime = this->pro_enter_de->date();
        push_entertime = entertime.toString();
        QDate outtime = this->pro_out_de->date();
        push_outtime = outtime.toString();
        push_status = this->pro_status_cbx->currentText();
        push_note = this->pro_note_tEt->toPlainText();
        QString tabname = this->pro_name_cbx->currentText();


    } else {
        QMessageBox::warning(this, "警告", "未输入板号");
    }
}
