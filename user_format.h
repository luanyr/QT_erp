#ifndef USER_FORMAT_H
#define USER_FORMAT_H
#include <QString>
class user_info{
public:
    user_info(const QString &username, const QString &password, const QString &role);
    QString get_username();
    QString get_password();
    QString get_role();
private:
    QString m_username;
    QString m_password;
    QString m_role;
};

#endif // USER_FORMAT_H

