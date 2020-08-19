#include "add_proinfo.h"
#include "ui_add_proinfo.h"

add_proinfo::add_proinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_proinfo)
{
    ui->setupUi(this);
    this->set_format();
    connect(confirm_btn, &QPushButton::clicked, this, &add_proinfo::enable_push);
    connect(push_btn, &QPushButton::clicked, this, &add_proinfo::push2db);
    connect(select_file_btn, &QPushButton::clicked, this, &add_proinfo::select_save_file);
    connect(this, &add_proinfo::add_ok, this, &add_proinfo::close);
}

add_proinfo::~add_proinfo()
{
    UserDB->DataBase_Close();
    delete ui;
}

void add_proinfo::set_format()
{
    this->resize(600,400);
    QDate current_date = QDate::currentDate();
    ft.setPointSize(12);
    /*产品名lab&cbx*/
    pro_name_lab = new QLabel(this);
    pro_name_lab->move(10, 20);
    pro_name_lab->setFont(ft);
    pro_name_lab->setText(QString("产品名"));
    UserDB = new DataBase("Production.db");
    UserDB->DataBase_Connect();
    pro_name_cbx = new QComboBox(this);
    pro_name_cbx->move(10, 50);
    pro_name_cbx->resize(120, 30);
    QStringList tablist = UserDB->DataBase_GetAllTab();
    bool val = tablist.contains("sqlite_sequence");
    if(val == true)
    {
        tablist.removeOne("sqlite_sequence");
        tablist.removeDuplicates();//去重
    }
    QStringListIterator tabitr(tablist);
    while(tabitr.hasNext())
    {
        QString tabname = tabitr.next().toLocal8Bit();
        pro_name_cbx->addItem(tabname);
    }
    UserDB->DataBase_Close();
    /*板号lab&linedit*/
    pro_no_lab = new QLabel(this);
    pro_no_lab->move(10, 130);
    pro_no_lab->setFont(ft);
    pro_no_lab->setText(QString("板号"));
    pro_no_lEd = new QLineEdit(this);
    pro_no_lEd->move(10, 160);
    pro_no_lEd->resize(120, 30);
    /*进入时间lab&date*/
    pro_entertime_lab = new QLabel(this);
    pro_entertime_lab->move(210, 20);
    pro_entertime_lab->setFont(ft);
    pro_entertime_lab->setText(QString("进入时间"));
    pro_enter_de = new QDateEdit(this);
    pro_enter_de->move(210, 50);
    pro_enter_de->resize(120, 30);
    pro_enter_de->setDate(current_date);
    pro_enter_de->setCalendarPopup(true);
    /*离开时间lab&date*/
    pro_outtime_lab = new QLabel(this);
    pro_outtime_lab->move(210, 130);
    pro_outtime_lab->setFont(ft);
    pro_outtime_lab->resize(120, 30);
    pro_outtime_lab->setText(QString("离开时间"));
    pro_out_de = new QDateEdit(this);
    pro_out_de->resize(120, 30);
    pro_out_de->move(210, 160);
    pro_out_de->setDate(current_date);
    pro_out_de->setCalendarPopup(true);
    /*状态lab&cbx*/
    pro_status_lab = new QLabel(this);
    pro_status_lab->move(10, 240);
    pro_status_lab->setFont(ft);
    pro_status_lab->setText(QString("状态"));
    pro_status_cbx = new QComboBox(this);
    pro_status_cbx->move(10, 270);
    pro_status_cbx->resize(120, 30);
    pro_status_cbx->addItem("待测试");
    pro_status_cbx->addItem("已测试");
    pro_status_cbx->addItem("测试出错");
    pro_status_cbx->addItem("维修中");
    /*备注lab&led*/
    pro_note_lab = new QLabel(this);
    pro_note_lab->move(360, 20);
    pro_note_lab->setFont(ft);
    pro_note_lab->setText(QString("备注"));
    pro_note_tEt = new QTextEdit(this);
    pro_note_tEt->move(360, 50);
    pro_note_tEt->resize(200,250);
    QString holderinfo = "请添加硬件与软件版本信息，异常状态（如有）及您认为需要备注的信息";
    holderinfo += '\n';
    holderinfo += "例如：<软件版本>：V1.00";
    holderinfo += '\n';
    holderinfo += "<异常>:无法上电";
    holderinfo += '\n';
    holderinfo += "<其他信息>:此办卡为客户返修";
    pro_note_tEt->setPlaceholderText(holderinfo);
    /*确认和提交btn*/
    confirm_btn = new QPushButton(this);
    confirm_btn->move(10, 350);
    confirm_btn->setFont(ft);
    confirm_btn->resize(120, 30);
    confirm_btn->setText("请确认信息");
    push_btn = new QPushButton(this);
    push_btn->move(230, 350);
    push_btn->setFont(ft);
    push_btn->resize(120, 30);
    push_btn->setText("提交");
    push_btn->setDisabled(true);
    /*测试日志lab&led*/
    select_file_btn = new QPushButton(this);
    select_file_btn->setFont(ft);
    select_file_btn->move(210, 240);
    select_file_btn->resize(120, 30);
    select_file_btn->setText("测试记录");
    file_path_lEd = new QLineEdit(this);
    file_path_lEd->resize(120, 30);
    file_path_lEd->move(210, 270);
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
        push_entertime = entertime.toString("yyyy-MM-dd");
        QDate outtime = this->pro_out_de->date();
        push_outtime = outtime.toString("yyyy-MM-dd");
        push_status = this->pro_status_cbx->currentText();
        push_note = this->pro_note_tEt->toPlainText();
        QString tabname = this->pro_name_cbx->currentText();
        new_pro_info = new pro_format(push_no, push_entertime, push_outtime, push_status, push_note, log_filename, file_conten);
        UserDB = new DataBase("Production.db");
        UserDB->DataBase_Connect();
        if(UserDB->DataBase_add_pro((*new_pro_info), tabname) == true) {
            UserDB->DataBase_Close();
            emit add_ok();
        } else {
            emit add_failed();
        }
    } else {
        QMessageBox::warning(this, "警告", "未输入板号");
    }
}

void add_proinfo::select_save_file()
{
    if(pro_status_cbx->currentIndex() == 0) {
      QMessageBox::warning(this, "警告", "目前状态为待测试，请先测试！");
    } else {
        file_path = QFileDialog::getOpenFileName(this, "Open file", ".");
        if(!file_path.isEmpty()) {
            QFile file(file_path);
            QFileInfo fileinfo(file);
            if(file.open(QIODevice::ReadOnly)) {
               QByteArray tdata = file.readAll();
               file_conten = qCompress(tdata, 9);
               log_filename = fileinfo.fileName();
               this->file_path_lEd->setText(file_path);
            }
        } else {
           QMessageBox::warning(this, "警告", "无此文件!");
        }
    }
}

