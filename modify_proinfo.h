#ifndef MODIFY_PROINFO_H
#define MODIFY_PROINFO_H

#include <QDialog>
#include "add_proinfo.h"
namespace Ui {
class modify_proinfo;
}

class modify_proinfo : public add_proinfo
{
    Q_OBJECT

public:
    explicit modify_proinfo(QWidget *parent = nullptr);
    ~modify_proinfo();

private:
    Ui::modify_proinfo *ui;
};

#endif // MODIFY_PROINFO_H
