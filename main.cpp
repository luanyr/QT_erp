#include "widget.h"
#include "login.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login *lg = new login();
    if(lg->exec() == QDialog::Accepted)
    {
        Widget w;
        w.setWindowTitle("产品管理系统");
        w.show();
        return a.exec();
    }
    return 0;
}
