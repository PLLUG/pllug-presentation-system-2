#ifndef HTMLIMPORT_H
#define HTMLIMPORT_H

#include <memory>
#include <QList>

class AbstractPresentationElementFactory;
class PresentationElement;
class QByteArray;
class HtmlImport
{
public:
    HtmlImport(std::shared_ptr<AbstractPresentationElementFactory> presentationElementFactory);

    QList<PresentationElement *> import(const QByteArray &inputHtml) const;

    std::shared_ptr<AbstractPresentationElementFactory> presentationElementFactory() const;

private:
    std::shared_ptr<AbstractPresentationElementFactory> mPresentationElementFactory;
};

#endif // HTMLIMPORT_H
