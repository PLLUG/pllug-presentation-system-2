#ifndef DOCUMENTIMPORTSTRATEGY_H
#define DOCUMENTIMPORTSTRATEGY_H

#include <memory>

class Presentation;
class QByteArray;
class PresentationElementFactory;

class DocumentImportStrategy
{
public:
    explicit DocumentImportStrategy(std::shared_ptr<PresentationElementFactory> presentationElementFactory);

    virtual std::unique_ptr<Presentation> import(const QByteArray &) const = 0;

    std::shared_ptr<PresentationElementFactory> presentationElementFactory() const;

private:
    std::shared_ptr<PresentationElementFactory> mPresentationElementFactory;
};

#endif // DOCUMENTIMPORTSTRATEGY_H
