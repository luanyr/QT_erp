#include "widget.h"
#include "login.h"
#include "log_dia.h"
#include <QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    login *lg = new login();
    if(lg->exec() == QDialog::Accepted)
    {
        Widget w;
        w.setWindowTitle("产品管理系统v.10 by Mr.luan");
        w.show();
        return a.exec();
    }
    return 0;
}
