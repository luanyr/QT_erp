#ifndef ADD_PROINFO_H
#define ADD_PROINFO_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QDate>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>
#include <QMessageBox>
#include "database.h"
#include "pro_format.h"
#include <QStringList>
#include <QStringListIterator>
#include <QFile>
#include <QFileDialog>
namespace Ui {
class add_proinfo;
}

class add_proinfo : public QDialog
{
    Q_OBJECT

public:
    explicit add_proinfo(QWidget *parent = nullptr);
    ~add_proinfo();

private:
    Ui::add_proinfo *ui;
    void set_format();
    DataBase *UserDB;
    pro_format *new_pro_info;
    QLabel *pro_name_lab;
    QLabel *pro_no_lab;
    QLabel *pro_entertime_lab;
    QLabel *pro_outtime_lab;
    QLabel *pro_status_lab;
    QLabel *pro_note_lab;
    QLabel *pro_log_lab;
    QLineEdit *pro_no_lEd;
    QLineEdit *file_path_lEd;
    QDateEdit *pro_enter_de;
    QDateEdit *pro_out_de;
    QComboBox *pro_status_cbx;
    QComboBox *pro_name_cbx;
    QTextEdit *pro_note_tEt;
    QPushButton *confirm_btn;
    QPushButton *push_btn;
    QPushButton *select_file_btn;
    QString file_path;
    QString push_no;
    QString push_entertime;
    QString push_outtime;
    QString push_status;
    QString push_note;
    QFileDialog *select_file;
    QByteArray file_conten;
    QString log_filename;
private slots:
    void enable_push();
    void push2db();
    void select_save_file();
};

#endif // ADD_PROINFO_H
