#ifndef PRESENTATIONELEMENTFACTORY_H
#define PRESENTATIONELEMENTFACTORY_H

#include <memory>

class PresentationElement;
class QString;

class PresentationElementFactory
{
public:
    std::unique_ptr<PresentationElement> create(const QString &text, const QString &tag);
};

#endif // PRESENTATIONELEMENTFACTORY_H
