#include "domdocumentdivider.h"
#include "presentationelementfactory.h"
#include "presentationelement.h"
#include "documentimportstrategy.h"
#include "presentation.h"
#include "slide.h"
#include "presentationelement.h"
#include "separator.h"
#include "header.h"

#include <QList>
#include <QDebug>
#include <memory>

const int cMaxNumOfElements = 5;

DomDocumentDivider::DomDocumentDivider()
{
}

std::unique_ptr<Presentation> DomDocumentDivider::import(const QList<PresentationElement *> &elements) const
{
    QList<QList<PresentationElement *>> separatedParts = divideBySeparators(elements);
    QList<Slide *> undividedSlides = divideByHeaders(separatedParts);

    std::unique_ptr<Presentation> rPresentation = divideSlides(undividedSlides);
    return rPresentation;
}

bool DomDocumentDivider::isSeparator(PresentationElement *element) const
{
    return dynamic_cast<Separator *>(element);
}

bool DomDocumentDivider::isHeader(PresentationElement *element) const
{
    return dynamic_cast<Header *>(element);
}

QList<QList<PresentationElement *> > DomDocumentDivider::divideBySeparators(const QList<PresentationElement *> &elements) const
{
    QList<QList<PresentationElement *> > rParts;

    QList<PresentationElement *> currentPart;
    for(auto element: elements)
    {
        if (isSeparator(element))
        {
            if (currentPart.count() != 0)
            {
                rParts.append(currentPart);
                currentPart.clear();
            }
        }
        else
        {
            currentPart.append(element);
        }
    }
    if (currentPart.count() != 0)
    {
        rParts.append(currentPart);
    }

    return rParts;
}

QList<Slide *> DomDocumentDivider::divideByHeaders(const QList<QList<PresentationElement *> > &parts) const
{
    QList<Slide *> rSlides;

    for (auto part: parts)
    {
        Slide *currentSlide = new Slide();
        for (auto element: part)
        {
            if (isHeader(element))
            {
                if(currentSlide->elementsCount() != 0)
                {
                    rSlides.append(currentSlide);
                    currentSlide = new Slide();
                }
                // addTitle() method would fit better
                currentSlide->addElement(std::unique_ptr<PresentationElement>(element));
            }
            else
            {
                currentSlide->addElement(std::unique_ptr<PresentationElement>(element));
            }
        }
        if(currentSlide->elementsCount() != 0)
        {
            rSlides.append(currentSlide);
        }
    }
    return rSlides;
}

std::unique_ptr<Presentation> DomDocumentDivider::divideSlides(const QList<Slide *> &slides) const
{
    std::unique_ptr<Presentation> rPresentation = std::make_unique<Presentation>();

    for (auto undividedSlide: slides)
    {
        QList<Slide *> smallerSlides = divideSlide(undividedSlide, cMaxNumOfElements);
        for (Slide *slide: smallerSlides)
        {
            rPresentation->appendSlide(std::unique_ptr<Slide>(slide));
        }
    }

    return rPresentation;
}

QList<Slide *>  DomDocumentDivider::divideSlide(Slide *slide, int elementsNum) const
{
    // TODO: Nothing done here yet, as we don't know how to divide a single slide
    QList<Slide *> smallerSlides;
    smallerSlides.push_back(slide);
    return smallerSlides;
}
