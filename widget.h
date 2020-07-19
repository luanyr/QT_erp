#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qlabel.h>
#include "login.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QLabel *title_lab;
    QLabel *username_lab;
    QLabel *username_real;
};

#endif // WIDGET_H
