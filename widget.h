#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qlabel.h>
#include "login.h"
#include "add_new.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void display_userandrole();
    void set_pushbutton();
public slots:
    void add_new();
private:
    Ui::Widget *ui;
    class DataBase *UserDB;
    class add_new *adn;
    QLabel *title_lab;
    QLabel *username_lab;
    QLabel *username_real;
    QLabel *userrole_lab;
    QLabel *userrole_real;
    QPushButton *add_new_btn;
};

#endif // WIDGET_H
