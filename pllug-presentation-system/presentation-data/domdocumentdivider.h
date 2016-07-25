#ifndef DOMDOCUMENTDIVIDER_H
#define DOMDOCUMENTDIVIDER_H

#include "documentimportstrategy.h"

class Presentation;
class Slide;
class PresentationElement;
#include <QList>

class DomDocumentDivider : public DocumentImportStrategy
{
public:
    explicit DomDocumentDivider();
    virtual std::unique_ptr<Presentation> import(const QList<PresentationElement *> &elements) const override;

private:
    bool isSeparator(PresentationElement *element) const;
    bool isHeader(PresentationElement *element) const;

    QList<QList<PresentationElement *>> divideBySeparators(const QList<PresentationElement *> &elements) const;
    QList<Slide *> divideByHeaders(const QList<QList<PresentationElement *>> &parts) const;
    std::unique_ptr<Presentation> divideSlides(const QList<Slide *> &slides) const;
    QList<Slide *> divideSlide(Slide *slide, int elementsNum) const;
};

#endif // DOMDOCUMENTDIVIDER_H
