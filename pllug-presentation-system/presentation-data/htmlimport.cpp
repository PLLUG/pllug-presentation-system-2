#include "htmlimport.h"
#include "presentationelementfactory.h"
#include "presentationElement.h"

#include <QDomDocument>
#include <QDebug>
#include <QByteArray>

HtmlImport::HtmlImport(std::shared_ptr<PresentationElementFactory> presentationElementFactory)
    : mPresentationElementFactory(presentationElementFactory)
{
}

QList<PresentationElement *> HtmlImport::import(const QByteArray &inputHtml) const
{
    QList<PresentationElement *> rElements;

    QDomDocument htmlDocument;
    htmlDocument.setContent(inputHtml);

    QDomNode domNode = htmlDocument.documentElement().firstChild();
    while (!(domNode.isNull()))
    {
        QDomElement domElement = domNode.toElement();
        if (!domElement.isNull())
        {
            QString htmlElement( "<" + domElement.tagName() + ">" + domElement.text() + "</" + domElement.tagName() + ">");
            PresentationElement* element = presentationElementFactory()->create(htmlElement).release();
            rElements.append(element);
        }
        domNode = domNode.nextSiblingElement();
    }

    return rElements;
}

std::shared_ptr<PresentationElementFactory> HtmlImport::presentationElementFactory() const
{
    return mPresentationElementFactory;
}
