#ifndef ROLEPROVIDER_H
#define ROLEPROVIDER_H

#include "iroleprovider.h"

class RoleProvider : public IRoleProvider
{
public:
    virtual QHash<int, QByteArray> roleNameByValue() const;
    void addRole(int val, const QByteArray &name);

private:
     QHash<int, QByteArray> mRoleNamesByValue;
};

#endif // ROLEPROVIDER_H
