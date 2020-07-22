#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(1500, 1000);
    //this->
    //输出用户名，以及权限；
    this->display_userandrole();
    this->set_pushbutton();
    UserDB = new DataBase("Production.db");
    UserDB->DataBase_Connect();
    //UserDB->DataBase_ClearTab("all");
    this->set_tabname_cbx();
    //pro_info = new pro_format("111", "0722", "0723", "OK", "good");
    //UserDB->DataBase_add_pro(*pro_info, "vme");
    connect(add_new_btn, &QPushButton::clicked, this, &Widget::add_new);
    connect(Dis_AllTab_btn, &QPushButton::clicked, this, &Widget::display_all_tab);
    connect(dis_proinfo_btn, &QPushButton::clicked, this, &Widget::dis_pro_info);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::display_userandrole()
{
    QFont ft;
    ft.setPointSize(12);
    username_lab = new QLabel(this);
    username_lab->move(30,20);
    username_lab->setFont(ft);
    username_lab->setText("用户名:");
    username_real = new QLabel(this);
    username_real->move(120,20);
    username_real->setFont(ft);
    username_real->setText(q_username);
    userrole_lab = new QLabel(this);
    userrole_lab->move(200, 20);
    userrole_lab->setFont(ft);
    userrole_lab->setText("权限：");
    userrole_real = new QLabel(this);
    userrole_real->move(270, 20);
    userrole_real->setFont(ft);
    userrole_real->setText(q_role);
}

void Widget::set_pushbutton()
{
    QFont ft;
    ft.setPointSize(10);
    add_new_btn = new QPushButton(this);
    add_new_btn->move(30, 60);
    add_new_btn->setFont(ft);
    add_new_btn->setText("添加新项目");
    Dis_AllTab_btn = new QPushButton(this);
    Dis_AllTab_btn->move(150, 60);
    Dis_AllTab_btn->setFont(ft);
    Dis_AllTab_btn->setText("显示项目名");
    dis_proinfo_btn = new QPushButton(this);
    dis_proinfo_btn->move(270, 60);
    dis_proinfo_btn->setFont(ft);
    dis_proinfo_btn->setText("显示产品信息");
}

void Widget::set_tabname_cbx()
{
    QFont ft;
    ft.setPointSize(10);
    tab_name_cbx = new QComboBox(this);
    tab_name_cbx->move(30, 120);
    tab_name_cbx->setFont(ft);
}

void Widget::add_new()
{
    adn = new class add_new(this);
    if(adn->exec() == QDialog::Accepted)
    {
        //adn->close();
    }
}

void Widget::display_all_tab()
{
    UserDB = new DataBase("Production.db");
    UserDB->DataBase_Connect();
    this->tablist = UserDB->DataBase_GetAllTab();
    bool val = this->tablist.contains("sqlite_sequence");
    if(val == true)
    {
        this->tablist.removeOne("sqlite_sequence");
    }
    QStringListIterator tabitr(this->tablist);
    while (tabitr.hasNext()) {
        QString tabname = tabitr.next().toLocal8Bit();
        this->tab_name_cbx->addItem(tabname);
    }
}

void Widget::dis_pro_info()
{
    UserDB = new DataBase("Production.db");
    UserDB->DataBase_Connect();
    QString tabname = this->tab_name_cbx->currentText().toLocal8Bit();
    pro_tabview = new QTableView(this);
    UserDB->DataBase_P2Tabview(pro_tabview, tabname);
}
