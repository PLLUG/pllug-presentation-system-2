#ifndef CONCRETEPRESENTATIONELEMENTFACTORY_H
#define CONCRETEPRESENTATIONELEMENTFACTORY_H

#include "presentationelementfactory.h"

class ConcretePresentationElementFactory : public PresentationElementFactory
{
public:
    virtual std::unique_ptr<PresentationElement> create(const QString &text, const QString &tag) const override;
};

#endif // CONCRETEPRESENTATIONELEMENTFACTORY_H
