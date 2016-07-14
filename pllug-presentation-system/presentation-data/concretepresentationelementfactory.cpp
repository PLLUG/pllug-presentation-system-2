#include "concretepresentationelementfactory.h"

#include "presentationelement.h"

std::unique_ptr<PresentationElement> ConcretePresentationElementFactory::create(const QString &text, const QString &tag) const
{
    return std::unique_ptr<PresentationElement>();
}
