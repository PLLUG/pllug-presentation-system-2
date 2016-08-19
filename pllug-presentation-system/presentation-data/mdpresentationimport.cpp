#include "mdpresentationimport.h"

#include "presentation.h"
#include "mdhtmlimport.h"
#include "htmlimport.h"
#include "domdocumentdivider.h"
#include "presentationelementfactory.h"

#include <QString>
#include <QByteArray>
#include <QList>

std::unique_ptr<Presentation> MdPresentationImport::import(const QString &mdFilePath) const
{
    MdHtmlImport mdToHtml;
    std::unique_ptr<QByteArray> html(mdToHtml.import(mdFilePath).release());

    HtmlImport htmlToElements(std::shared_ptr<PresentationElementFactory>(new PresentationElementFactory));
    QList<PresentationElement *> presentationElements(htmlToElements.import(*html));

    DomDocumentDivider elementsToPresentation;
    return elementsToPresentation.import(presentationElements);
}
