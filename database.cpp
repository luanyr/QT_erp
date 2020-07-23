#include "database.h"

DataBase::DataBase(QString db_name)
{
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName(db_name);
}

DataBase::~DataBase()
{
    DB.close();
}

bool DataBase::DataBase_Connect()
{
    if(!DB.open())
    {
        return false;
    } else {
        qDebug() << "database open success" << endl;
        return true;
    }
}

void DataBase::DataBase_Close()
{
    DB.close();
}

bool DataBase::DataBase_createTab(QString tab_name,bool tab_type)
{
    query = new QSqlQuery;
    if(tab_type == 0)
    {
        QString str = "create table if not exists " + tab_name + " (" +
                      "[id] integer primary key autoincrement," +
                      "[username] varchar(30)," +
                      "[password] varchar(30)," +
                      "[role] varchar(30)" +
                      ")";
        if(!query->exec(str))
            return false;
        return true;
    } else if(tab_type == 1){
        QString str = "create table if not exists " + tab_name + " (" +
                      "[id] integer primary key autoincrement," +
                      "[Pro_No] varchar(30)," +
                      "[Enter_Time] varchar(30)," +
                      "[Out_Time] varchar(30)," +
                      "[Status] varchar(30)," +
                      "[Note] varchar(30)" +
                      ")";
        if(!query->exec(str))
            return false;
        return true;
    }
    return false;
}

void DataBase::DataBase_insert(user_info &user_info, bool insert_type, QString tab_name)
{
    query = new QSqlQuery;
    if(insert_type == 0)
    {
        query->prepare("INSERT INTO " + tab_name + " VALUES (:id,:username,:password,:role)");
        query->bindValue(":username", user_info.get_username());
        query->bindValue(":password", user_info.get_password());
        query->bindValue(":role", user_info.get_role());
        if(!query->exec())
        {
            qDebug() << query->lastError() << endl;
        } else {
            qDebug() << "insert success" << endl;
        }
    }
}

QString DataBase::DataBase_SelectTab(QString tab_name, QString type_name, QString real_name, QString return_typename)
{
    query = new QSqlQuery;
    if(!query->exec(QString("select * from %1 where %2='%3'").arg(tab_name).arg(type_name).arg(real_name)))
    {
        qDebug() << query->lastError() << endl;
    } else {
        query->next();
        //int id = query->value(0).toInt();
        QString username = query->value(1).toString();
        QString password = query->value(2).toString();
        QString role =  query->value(3).toString();
        if(return_typename == "password")
        {
            return password;
        } else if(return_typename == "role")
        {
            return role;
        }
    }
    return "0";
}
void DataBase::DataBase_displayTab(QString tab_name)
{
    query = new QSqlQuery;
    query->prepare("select * from " + tab_name);
    if(!query->exec())
    {
        qDebug() << query->lastError() << endl;
    } else {
        while (query->next()) {
            int id = query->value(0).toInt();
            QString username = query->value(1).toString();
            QString password = query->value(2).toString();
            QString role =  query->value(3).toString();
            qDebug() << QString("id:%1, username:%2, password:%3, role:%4").arg(id).arg(username).arg(password).arg(role);
        }
    }
}

void DataBase::DataBase_ClearTab(QString tab_name)
{
    QStringList tablist;

    query = new QSqlQuery;
    if(tab_name == "all")
    {
        tablist = this->DataBase_GetAllTab();
        QStringListIterator tabitr(tablist);
        while (tabitr.hasNext()) {
            query->prepare("drop table " + tabitr.next().toLocal8Bit());
            if(!query->exec())
            {
                qDebug() << query->lastError() << endl;
            } else {
                qDebug() << "clear tab success" << endl;
            }
        }
    } else {
        query->prepare("drop table " + tab_name);
        if(!query->exec())
        {
            qDebug() << query->lastError() << endl;
        } else {
            qDebug() << "clear tab success" << endl;
        }
    }
}

bool DataBase::DataBase_IsTabExist(QString tab_name)
{
    if(DB.tables().contains(tab_name))
    {
        return true;
    } else {
        return false;
    }
}

QStringList DataBase::DataBase_GetAllTab()
{
    QStringList tables = DB.tables();
    return  tables;
}

void DataBase::DataBase_add_pro(pro_format &pro_info, QString tab_name)
{
    query = new QSqlQuery;
    query->prepare("INSERT INTO " + tab_name + " VALUES (:id,:Pro_No,:Enter_Time,:Out_Time,:Status,:Note)");
    query->bindValue(":Pro_No", pro_info.get_prono());
    query->bindValue(":Enter_Time", pro_info.get_entertime());
    query->bindValue(":Out_Time", pro_info.get_outtime());
    query->bindValue(":Status", pro_info.get_prostatus());
    query->bindValue(":Note", pro_info.get_pronote());
    if(!query->exec())
    {
        qDebug() << query->lastError() << endl;
    } else {
        qDebug() << "insert success" << endl;
    }

}

void DataBase::DataBase_P2Tabview(QTableView *tabview, QString tabname)
{
    static QSqlQueryModel *model = new QSqlQueryModel(tabview);
    model->setQuery("select * from " + tabname + ";");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("序号"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("板号"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("进入时间"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("离开时间"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("状态"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("备注"));
    tabview->setModel(model);
}
