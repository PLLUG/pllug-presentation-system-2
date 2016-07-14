#ifndef PRESENTATIONELEMENTFACTORY_H
#define PRESENTATIONELEMENTFACTORY_H

#include <memory>

class PresentationElement;
class QString;

class PresentationElementFactory
{
public:
    virtual std::unique_ptr<PresentationElement> create(const QString &text, const QString &tag) const = 0;
};

#endif // PRESENTATIONELEMENTFACTORY_H
