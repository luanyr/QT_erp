#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QApplication>
#include <QDebug>
#include <QString>
#include <QDir>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QTableView>
#include <QStandardItemModel>
#include "user_format.h"
#include "pro_format.h"
#include <qsqlquerymodel.h>
class DataBase
{
public:
    DataBase(QString db_name);
    ~DataBase();
    bool DataBase_Connect();
    bool DataBase_createTab(QString tab_name, bool tab_type);
    void DataBase_insert(user_info &user_info, bool insert_type, QString tab_name);
    bool DataBase_add_pro(pro_format &pro_info, QString tab_name);
    void DataBase_Close();
    void DataBase_displayTab(QString tab_name);
    QString DataBase_SelectTab(QString tab_name, QString type_name, QString real_name, QString return_typename);
    QByteArray DataBase_SelectTab(QString tab_name, QString real_name,QString type_name);
    void DataBase_ClearTab(QString tab_name);
    bool DataBase_IsTabExist(QString tab_name);
    QStringList DataBase_GetAllTab();
    void DataBase_P2Tabview(QTableView *tabview, QString tabname);
    bool DataBase_modify(QString tabname, QString prono, pro_format &pro_info);
    bool DataBase_delete(QString tabname,QString prono);

private:
    QSqlQuery *query;
    QSqlQueryModel *qmodel;
    QSqlDatabase DB;
    bool DBStatus;
};

#endif // DATABASE_H
