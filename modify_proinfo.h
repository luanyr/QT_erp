#ifndef MODIFY_PROINFO_H
#define MODIFY_PROINFO_H

#include <QDialog>
#include "add_proinfo.h"
#include "pro_format.h"
namespace Ui {
class modify_proinfo;
}

class modify_proinfo : public add_proinfo
{
    Q_OBJECT

public:
    explicit modify_proinfo(pro_format modify_info);
    ~modify_proinfo();

private:
    Ui::modify_proinfo *ui;
    void set_modifycontent();
    QString mdy_prono;
    QString mdy_proentertime;
    QString mdy_proouttime;
    QString mdy_prostatus;
    QString mdy_pronote;
    QString mdy_filename;
    pro_format *m_modifyinfo;
    QPushButton *delete_btn;
    void modify_setformat();
    void delete_warning();
    virtual void push2db();
signals:
    void confirm_delete();
    void cancel_delete();
private slots:
    void delete_proinfo();
};

#endif // MODIFY_PROINFO_H
