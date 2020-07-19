#include "user_format.h"

user_info::user_info(const QString &username, const QString &password, const QString &role)
{
    this->m_username = username;
    this->m_password = password;
    this->m_role = role;
}

QString user_info::get_username()
{
    return this->m_username;
}
QString user_info::get_password()
{
    return this->m_password;
}
QString user_info::get_role()
{
    return this->m_role;
}
