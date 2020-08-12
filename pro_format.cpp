#include "pro_format.h"

pro_format::pro_format(QString pro_no, QString enter_time, QString out_time, QString pro_status, QString pro_note, QString pro_logname, QByteArray pro_logcontent)
{
    this->m_pro_no = pro_no;
    this->m_enter_time = enter_time;
    this->m_out_time = out_time;
    this->m_pro_status = pro_status;
    this->m_pro_note = pro_note;
    this->m_pro_logname = pro_logname;
    this->m_pro_logcontent = pro_logcontent;
}

pro_format::pro_format(QString pro_no, QString enter_time, QString out_time, QString pro_status, QString pro_note, QString pro_logname)
{
    this->m_pro_no = pro_no;
    this->m_enter_time = enter_time;
    this->m_out_time = out_time;
    this->m_pro_status = pro_status;
    this->m_pro_note = pro_note;
    this->m_pro_logname = pro_logname;
}

QString pro_format::get_prono()
{
    return this->m_pro_no;
}

QString pro_format::get_entertime()
{
    return this->m_enter_time;
}

QString pro_format::get_outtime()
{
    return this->m_out_time;
}

QString pro_format::get_prostatus()
{
    return this->m_pro_status;
}

QString pro_format::get_pronote()
{
    return this->m_pro_note;
}

QString pro_format::get_logname()
{
    return  this->m_pro_logname;
}

QByteArray pro_format::get_logcontent()
{
    return this->m_pro_logcontent;
}
