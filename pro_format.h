#ifndef PRO_FORMAT_H
#define PRO_FORMAT_H
#include <QString>

class pro_format
{
public:
    pro_format(QString pro_no, QString enter_time, QString out_time, QString pro_status, QString pro_note);
    QString get_prono();
    QString get_entertime();
    QString get_outtime();
    QString get_prostatus();
    QString get_pronote();
private:
    QString m_pro_no;
    QString m_enter_time;
    QString m_out_time;
    QString m_pro_status;
    QString m_pro_note;
};

#endif // PRO_FORMAT_H
