#ifndef PRESENTATIONELEMENTFACTORY_H
#define PRESENTATIONELEMENTFACTORY_H

#include <memory>
#include <QString>

#include "presentationelement.h"

class PresentationElementFactory
{
public:
    std::unique_ptr<PresentationElement> create(const QString &text, const QString &tag);
};

#endif // PRESENTATIONELEMENTFACTORY_H
