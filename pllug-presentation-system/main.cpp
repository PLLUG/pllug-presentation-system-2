#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFile>
#include <memory>
#include <QList>
#include <QQmlContext>

#include "domdocumentdivider.h"
#include "htmlimport.h"
#include "presentationelement.h"
#include "presentationelementfactory.h"
#include "presentationmodel.h"
#include "slideproxymodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QFile htmlFile("D:/Qt_projects/SUMMERCAMP2016/pps2/pllug-presentation-system-2/tests/auto/resources/separator_headers.html");
    htmlFile.open(QFile::ReadOnly);
    QByteArray input = htmlFile.readAll();
    htmlFile.close();
    std::shared_ptr<PresentationElementFactory> factoryPtr(new PresentationElementFactory());
    HtmlImport importObject(factoryPtr);
    QList<PresentationElement *> elements = importObject.import(input);
    DomDocumentDivider divider;
    std::unique_ptr<Presentation> presentation = divider.import(elements);

    PresentationModel presentationModel;
    presentationModel.setPresentation(presentation.release());
    SlideProxyModel slideModel;
    slideModel.setSourceModel(&presentationModel);
    slideModel.setSlideNumber(0);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("slideModel", &slideModel);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
