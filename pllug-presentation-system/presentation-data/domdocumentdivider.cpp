#include "domdocumentdivider.h"
#include "presentationelementfactory.h"
#include "presentation.h"
#include "slide.h"

#include <QVector>
#include <QDebug>
#include <QDomDocument>
#include <QByteArray>

const int cMaxNumOfElements = 5;

DomDocumentDivider::DomDocumentDivider(std::shared_ptr<PresentationElementFactory> presentationElementFactory)
    : DocumentImportStrategy(presentationElementFactory)
{
}

std::unique_ptr<Presentation> DomDocumentDivider::import(const QByteArray &inputText) const
{
    QByteArray htmlText = "<root>" + inputText + "</root>";
    QDomDocument htmlDocument;
    htmlDocument.setContent(htmlText);

    QVector<QDomDocument> separatedParts = divideBySeparators(htmlDocument);
    QVector<Slide> undividedSlides = divideByHeaders(separatedParts);

    return divideSlides(undividedSlides);
}

bool DomDocumentDivider::isSeparator(const QDomElement &element) const
{
    return element.tagName() == "hr";
}

bool DomDocumentDivider::isHeader(const QDomElement &element) const
{
    return element.tagName() == "h1";
}

QVector<QDomDocument> DomDocumentDivider::divideBySeparators(const QDomDocument &htmlDocument) const
{
    QVector<QDomDocument> rParts;
    QDomDocument currentPart;

    QDomNode domNode = htmlDocument.documentElement().firstChild();
    while (!(domNode.isNull()))
    {
        QDomElement domElement;
        domElement = domNode.toElement();
        if (!domElement.isNull())
        {
            qDebug() << "tag:" << domElement.tagName() << "text" << domElement.text();
            if (isSeparator(domElement))
            {
                if (currentPart.childNodes().count() != 0)
                {
                    rParts.push_back(currentPart);
                    currentPart = QDomDocument();
                }
            }
            else
            {
                currentPart.appendChild(domNode);
            }
        }
        domNode = domNode.nextSiblingElement();
    }

    if (currentPart.childNodes().count() != 0)
    {
        rParts.push_back(currentPart);
    }

    return rParts;
}

QVector<Slide> DomDocumentDivider::divideByHeaders(const QVector<QDomDocument> &parts) const
{
    QVector<Slide> rSlides;
    Slide currentSlide;

    for (const QDomDocument &part: parts)
    {
        QDomNode domNode = part.documentElement().firstChild();
        while (!domNode.isNull())
        {
            QDomElement domElement;
            domElement = domNode.toElement();
            if (!(domElement.isNull()))
            {
                qDebug() << "tag:" << domElement.tagName() << "text" << domElement.text();
                if (isHeader(domElement))
                {
                    if (currentSlide.elementsCount() != 0)
                    {
                        rSlides.push_back(currentSlide);
                        // FIXME: Needed constructor doesn't yet exist
//                                            currentSlide = Slide(domElement.text());
                    }
                }
                else
                {
                    // FIXME: Method PresentationElementFactory::create() isn't yet implemented.
//                    currentSlide.addElement(presentationElementFactory()->create(domElement.text(), domElement.tagName()));
                }
            }
            domNode = domNode.nextSiblingElement();
        }
        if (currentSlide.elementsCount() != 0)
        {
            rSlides.push_back(currentSlide);
        }
    }

    return rSlides;
}

std::unique_ptr<Presentation> DomDocumentDivider::divideSlides(const QVector<Slide> &slides) const
{
    std::unique_ptr<Presentation> rPresentation(new Presentation());

    for (const Slide &undividedSlide: slides)
    {
        QVector<Slide *> smallerSlides = divideSlide(undividedSlide, cMaxNumOfElements);
        for (Slide *slide: smallerSlides)
        {
            rPresentation->appendSlide(std::make_unique<Slide>(*slide));
        }
    }

    return rPresentation;
}

QVector<Slide *>  DomDocumentDivider::divideSlide(const Slide &slide, int elementsNum) const
{
    // TODO: Nothing done here yet, as we don't know how to divide a single slide
    return QVector<Slide *>();
}
