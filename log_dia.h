#ifndef LOG_DIA_H
#define LOG_DIA_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
namespace Ui {
class log_dia;
}

class log_dia : public QDialog
{
    Q_OBJECT

public:
    explicit log_dia(QWidget *parent = nullptr);
    ~log_dia();
    void set_log(QByteArray Qba_log);
    void set_note(QString Qstr_note);
private:
    Ui::log_dia *ui;
    QTextEdit *log_TEt;
    QPushButton *exit_btn;
    void set_format();

};

#endif // LOG_DIA_H
