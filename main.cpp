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
        w.show();
        return a.exec();
    }
    return 0;
}
