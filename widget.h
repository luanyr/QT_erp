#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qlabel.h>
#include <QComboBox>
#include <QTableView>
#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QTextCodec>
#include <QModelIndex>
#include "pro_format.h"
#include "login.h"
#include "add_new.h"
#include "add_proinfo.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void add_new();
    void add_pro();
private:
    Ui::Widget *ui;
    class DataBase *UserDB;
    class add_new *adn;
    class add_proinfo *adp;
    QLabel *title_lab;
    QLabel *username_lab;
    QLabel *username_real;
    QLabel *userrole_lab;
    QLabel *userrole_real;
    QPushButton *add_new_btn;
    QPushButton *Dis_AllTab_btn;
    QPushButton *dis_proinfo_btn;
    QPushButton *add_pro_btn;
    QComboBox *tab_name_cbx;
    pro_format *pro_info;
    QTableView *pro_tabview;
    QStringList tablist;
    void set_tabview();
    void display_userandrole();
    void set_pushbutton();
    void display_all_tab();
    void set_tabname_cbx();
    void dis_pro_info();
private slots:
    void tab_doubleClick(const QModelIndex);
};

#endif // WIDGET_H
