#ifndef MDPRESENTATIONIMPORT_H
#define MDPRESENTATIONIMPORT_H

#include <memory>
class Presentation;
class QString;

class MdPresentationImport
{
public:
    std::unique_ptr<Presentation> import(const QString &mdFilePath) const;
};

#endif // MDPRESENTATIONIMPORT_H
