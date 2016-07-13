#ifndef DOCUMENTIMPORTSTRATEGY_H
#define DOCUMENTIMPORTSTRATEGY_H

#include "presentation.h"

#include <QByteArray>
#include <memory>

class DocumentImportStrategy
{
public:
    virtual std::unique_ptr<Presentation> import(const QByteArray &) = 0;
};

#endif // DOCUMENTIMPORTSTRATEGY_H
