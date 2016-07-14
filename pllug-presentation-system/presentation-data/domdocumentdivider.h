#ifndef DOMDOCUMENTDIVIDER_H
#define DOMDOCUMENTDIVIDER_H

#include "documentimportstrategy.h"

class QDomDocument;
class QDomElement;
class Presentation;
class Slide;

template <typename T>
class QVector;

class DomDocumentDivider : public DocumentImportStrategy
{
public:
    explicit DomDocumentDivider(std::shared_ptr<PresentationElementFactory> presentationElementFactory);
    virtual std::unique_ptr<Presentation> import(const QByteArray &inputText) const override;

private:
    bool isSeparator(const QDomElement &element) const;
    bool isHeader(const QDomElement &element) const;

    QVector<QDomDocument> divideBySeparators(const QDomDocument &htmlDocument) const;
    QVector<Slide> divideByHeaders(const QVector<QDomDocument> &parts) const;
    std::unique_ptr<Presentation> divideSlides(const QVector<Slide> &slides) const;
    QVector<Slide *> divideSlide(const Slide &slide, int elementsNum) const;
};

#endif // DOMDOCUMENTDIVIDER_H
