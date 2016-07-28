#ifndef IROLEPROVIDER_H
#define IROLEPROVIDER_H

#include <QHash>
#include <QByteArray>

class IRoleProvider
{
public:
    virtual QHash<int, QByteArray> roleNameByValue() const = 0;
};

#endif // IROLEPROVIDER_H
