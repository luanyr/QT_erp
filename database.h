#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QApplication>
#include <QDebug>
#include <QString>
#include <QDir>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include "user_format.h"

class DataBase
{
public:
    DataBase(QString db_name);
    ~DataBase();
    bool DataBase_Connect();
    bool DataBase_createTab(QString tab_name, bool tab_type);
    void DataBase_insert(user_info &user_info, bool insert_type, QString tab_name);
    void DataBase_Close();
    void DataBase_displayTab(QString tab_name);
    QString DataBase_SelectTab(QString tab_name, QString type_name, QString real_name, QString return_typename);
    void DataBase_ClearTab(QString tab_name);
    bool DataBase_IsTabExist(QString tab_name);

private:
    QSqlQuery *query;
    QSqlDatabase DB;
    bool DBStatus;
};

#endif // DATABASE_H
