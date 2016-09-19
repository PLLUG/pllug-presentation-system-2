#include "mdpresentationimport.h"

#include "presentation.h"
#include "htmlimport.h"
#include "pandocrunner.h"
#include "paramsbuilder.h"
#include "domdocumentdivider.h"
#include "presentationelementfactory.h"

#include <QString>
#include <QByteArray>
#include <QList>
#include <QUrl>

using namespace PandocSlave;

const QLatin1String cPandocPath {"../pandoc-slave/pandoc/pandoc.exe"};
const QLatin1String cHtmlTemplate {"../pandoc-slave/pandoc/template.html"};

MdPresentationImport::MdPresentationImport(QObject *parent):
    QObject(parent),
    mPandocRunner(new PandocRunner(cPandocPath, this))
{
    connect(mPandocRunner, &PandocRunner::finished,
            this, &MdPresentationImport::parsePresentation, Qt::UniqueConnection);
}

void MdPresentationImport::import(const QString &mdFilePath) const
{
    ParamsBuilder builder;
    builder.addParam(ParamsBuilder::from, ParamsBuilder::Markdown_Github);
    builder.addParam(ParamsBuilder::to, ParamsBuilder::HTML);
    builder.addParam(ParamsBuilder::standalone, "");
    builder.addParam(ParamsBuilder::template_file, cHtmlTemplate);
    builder.addParam(ParamsBuilder::empty, QUrl(mdFilePath).toLocalFile());

    mPandocRunner->setParams(builder.params());
    mPandocRunner->run();
}

void MdPresentationImport::parsePresentation()
{
    if(mPandocRunner->error().isEmpty())
    {
        HtmlImport htmlToElements(std::shared_ptr<PresentationElementFactory>(new PresentationElementFactory));
        QList<PresentationElement *> presentationElements(htmlToElements.import(mPandocRunner->content().toUtf8()));
        DomDocumentDivider elementsToPresentation;
        emit presentationParsed(elementsToPresentation.import(presentationElements).release());
    }
}
