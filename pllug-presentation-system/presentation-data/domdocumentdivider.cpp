#include "domdocumentdivider.h"

const int cMaxNumOfElements = 5;

std::unique_ptr<Presentation> DomDocumentDivider::import(const QByteArray &inputText)
{
    QByteArray htmlText = "<root>" + inputText + "</root>";
    QDomDocument htmlDocument;
    htmlDocument.setContent(htmlText);

    QVector<QDomDocument> separatedParts = divideBySeparators(htmlDocument);
    QVector<Slide> undividedSlides = divideByHeaders(separatedParts);

    return std::make_unique<Presentation>(*divideSlides(undividedSlides));
}

bool DomDocumentDivider::isSeparator(const QDomElement &element)
{
    return element.tagName() == "hr";
}

bool DomDocumentDivider::isHeader(const QDomElement &element)
{
    return element.tagName() == "h1";
}

QVector<QDomDocument> DomDocumentDivider::divideBySeparators(const QDomDocument &htmlDocument)
{
    QVector<QDomDocument> rParts;
    QDomDocument currentPart;

    QDomNode domNode = htmlDocument.documentElement().firstChild();
    QDomElement domElement;
    while(!(domNode.isNull()))
    {
        domElement = domNode.toElement();
        if(!(domElement.isNull()))
        {
            qDebug() << "tag:" << domElement.tagName() << "text" << domElement.text();
            if (isSeparator(domElement))
            {
                if(currentPart.childNodes().count() != 0)
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

QVector<Slide> DomDocumentDivider::divideByHeaders(const QVector<QDomDocument> &parts)
{
    QVector<Slide> rSlides;
    Slide currentSlide;

    for (const QDomDocument &part: parts)
    {
        QDomNode domNode = part.documentElement().firstChild();
        QDomElement domElement;
        while(!(domNode.isNull()))
        {
            domElement = domNode.toElement();
            if(!(domElement.isNull()))
            {
                qDebug() << "tag:" << domElement.tagName() << "text" << domElement.text();
                if (isHeader(domElement))
                {
                    if (currentSlide.elementsCount() != 0)
                    {
                        rSlides.push_back(currentSlide);
                        // FIXME: Needed constructor doesn't yet exist
                        //                    currentSlide = Slide(domElement);
                    }
                }
                else
                {
                    // FIXME: Method PresentationElementFactory::create() isn't yet implemented.
                    //                    currentSlide.addElement(PresentationElementFactory().create(domElement.text(), domElement.tagName()));
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

Presentation *DomDocumentDivider::divideSlides(const QVector<Slide> &slides)
{
    Presentation *rPresentation = new Presentation();

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

QVector<Slide *> DomDocumentDivider::divideSlide(const Slide &slide, int elementsNum)
{
    // TODO: Nothing done here yet, as we don't know how to divide a single slide
    return QVector<Slide *>();
}
