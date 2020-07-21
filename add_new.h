#ifndef ADD_NEW_H
#define ADD_NEW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
namespace Ui {
class add_new;
}

class add_new : public QDialog
{
    Q_OBJECT

public:
    explicit add_new(QWidget *parent = nullptr);
    ~add_new();
    void set_format();
private:
    Ui::add_new *ui;
    QLabel *Proname_Lab;
    QLineEdit *Proname_LEd;
};

#endif // ADD_NEW_H
