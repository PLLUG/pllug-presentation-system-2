#include "roleprovider.h"

QHash<int, QByteArray> RoleProvider::roleNameByValue() const
{
    return mRoleNamesByValue;
}

void RoleProvider::addRole(int val, const QByteArray &name)
{
    mRoleNamesByValue.insert(val, name);
}
