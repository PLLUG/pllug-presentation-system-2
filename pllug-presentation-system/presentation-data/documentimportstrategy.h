#ifndef DOCUMENTIMPORTSTRATEGY_H
#define DOCUMENTIMPORTSTRATEGY_H

#include <memory>

class Presentation;
class QByteArray;

class DocumentImportStrategy
{
public:
    virtual std::unique_ptr<Presentation> import(const QByteArray &) const = 0;
};

#endif // DOCUMENTIMPORTSTRATEGY_H
