#ifndef TESTUTILITY_H
#define TESTUTILITY_H
#include <QString>

namespace TestUtility
{
QString getResourcePath(const QString &filename)
{
    return QString("%1/%2/%3").arg(EXECUTABLE_PATH).arg("resources").arg(filename);
}
}

#endif // TESTUTILITY_H
