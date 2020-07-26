#include "pro_format.h"

pro_format::pro_format(QString pro_no, QString enter_time, QString out_time, QString pro_status, QString pro_note)
{
    this->m_pro_no = pro_no;
    this->m_enter_time = enter_time;
    this->m_out_time = out_time;
    this->m_pro_status = pro_status;
    this->m_pro_note = pro_note;
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

QString pro_format::get_log()
{
    return  this->m_pro_log;
}
