#ifndef CONCRETEPRESENTATIONELEMENTFACTORY_H
#define CONCRETEPRESENTATIONELEMENTFACTORY_H

#include "abstractpresentationelementfactory.h"

class PresentationElementFactory : public AbstractPresentationElementFactory
{
public:
    virtual std::unique_ptr<PresentationElement> create(const QString &html) const override;
};

#endif // CONCRETEPRESENTATIONELEMENTFACTORY_H
