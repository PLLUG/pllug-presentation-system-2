#ifndef HTMLIMPORT_H
#define HTMLIMPORT_H

#include <memory>
#include <QList>

class PresentationElementFactory;
class PresentationElement;
class QByteArray;
class HtmlImport
{
public:
    HtmlImport(std::shared_ptr<PresentationElementFactory> presentationElementFactory);

    QList<PresentationElement *> import(const QByteArray &inputHtml) const;

    std::shared_ptr<PresentationElementFactory> presentationElementFactory() const;

private:
    std::shared_ptr<PresentationElementFactory> mPresentationElementFactory;
};

#endif // HTMLIMPORT_H
