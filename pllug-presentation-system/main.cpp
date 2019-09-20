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
#include "mdpresentationimport.h"
#include "presentationcontroller.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    PresentationController presentationController;
    SlideProxyModel slideModel;
    slideModel.setSourceModel(presentationController.presentationModel());

    QQmlApplicationEngine engine;
    engine.addImportPath(QLatin1String("qrc:/"));
    engine.rootContext()->setContextProperty(QLatin1String("presentationController"), &presentationController);
    engine.rootContext()->setContextProperty(QLatin1String("presentationModel"), presentationController.presentationModel());
    engine.rootContext()->setContextProperty(QLatin1String("slideModel"), &slideModel);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
