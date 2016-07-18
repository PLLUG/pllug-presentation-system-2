#ifndef DOCUMENTIMPORTSTRATEGY_H
#define DOCUMENTIMPORTSTRATEGY_H

#include <memory>
#include <QList>

class Presentation;
class QByteArray;
class PresentationElementFactory;
class PresentationElement;

class DocumentImportStrategy
{
public:
    explicit DocumentImportStrategy();

     virtual std::unique_ptr<Presentation> import(const QList<PresentationElement *> &) const = 0;

    std::shared_ptr<PresentationElementFactory> presentationElementFactory() const;

private:
    std::shared_ptr<PresentationElementFactory> mPresentationElementFactory;
};

#endif // DOCUMENTIMPORTSTRATEGY_H
