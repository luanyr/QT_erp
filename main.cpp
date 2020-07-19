#include "widget.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login *lg = new login();
    Widget w;
    if(lg->exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    return 0;
}
