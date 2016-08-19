#ifndef MDHTMLIMPORT_H
#define MDHTMLIMPORT_H

#include <memory>

class QByteArray;
class QString;

class MdHtmlImport
{
public:
    std::unique_ptr<QByteArray> import(const QString &mdFilePath) const;
};

#endif // MDHTMLIMPORT_H
