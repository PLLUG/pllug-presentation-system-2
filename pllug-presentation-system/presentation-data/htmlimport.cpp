#include "htmlimport.h"
#include "abstractpresentationelementfactory.h"
#include "presentationElement.h"

#include <QDomDocument>
#include <QByteArray>
#include <QTextStream>
HtmlImport::HtmlImport(std::shared_ptr<AbstractPresentationElementFactory> presentationElementFactory)
    : mPresentationElementFactory(presentationElementFactory)
{
}

QList<PresentationElement *> HtmlImport::import(const QByteArray &inputHtml) const
{
    QList<PresentationElement *> rElements;

    QDomDocument htmlDocument;
    htmlDocument.setContent(inputHtml);

    QDomNode domNode = htmlDocument.documentElement().firstChild();
    while (!domNode.isNull())
    {
        QDomElement domElement = domNode.toElement();
        if (!domElement.isNull())
        {
            QString content;
            QTextStream ts(&content);
            domElement.save(ts, domElement.childNodes().count());
            PresentationElement* element = presentationElementFactory()->create(content).release();
            rElements.append(element);
        }
        domNode = domNode.nextSiblingElement();
    }

    return rElements;
}

std::shared_ptr<AbstractPresentationElementFactory> HtmlImport::presentationElementFactory() const
{
    return mPresentationElementFactory;
}
