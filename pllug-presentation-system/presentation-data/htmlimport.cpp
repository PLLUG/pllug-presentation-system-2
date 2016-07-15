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

    QByteArray htmlText = "<root>" + inputHtml + "</root>";
    QDomDocument htmlDocument;
    htmlDocument.setContent(htmlText);

    QDomNode domNode = htmlDocument.documentElement().firstChild();
    while (!(domNode.isNull()))
    {
        QDomElement domElement = domNode.toElement();
        if (!domElement.isNull())
        {
            qDebug() << "tag:" << domElement.tagName() << "text" << domElement.text();
            QString htmlElement( "<" + domElement.tagName() + ">" + domElement.text() + "</" + domElement.tagName() + ">");
            rElements.append(presentationElementFactory()->create(htmlElement).release());
        }
        domNode = domNode.nextSiblingElement();
    }

    return rElements;
}

std::shared_ptr<PresentationElementFactory> HtmlImport::presentationElementFactory() const
{
    return mPresentationElementFactory;
}
