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
    QLabel *pro_no_lab;
    QLabel *pro_entertime_lab;
    QLabel *pro_outtime_lab;
    QLabel *pro_status_lab;
    QLabel *pro_note_lab;
    QLineEdit *pro_no_lEd;
    QDateEdit *pro_enter_de;
    QDateEdit *pro_out_de;
    QComboBox *pro_status_cbx;
    QTextEdit *pro_note_tEt;
    QPushButton *confirm_btn;
    QPushButton *push_btn;
    QString push_no;
    QString push_entertime;
    QString push_outtime;
    QString push_status;
    QString push_note;
private slots:
    void enable_push();
    void push2db();
};

#endif // ADD_PROINFO_H
