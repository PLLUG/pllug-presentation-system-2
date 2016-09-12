#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "presentationmodel.h"
#include "presentationmodelloader.h"
#include "presentationmodelfields.h"
#include <QDebug>
#include <QQmlContext>


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    PresentationLoader loader;
    loader.setFileName("D:/Summer CAmp/startup/pllug-presentation-system-2/pllug-presentation-system/recentPresentation.json");
    loader.load();

    PresentationModel data(&loader);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("recentModel", &data);
    engine.addImportPath(QStringLiteral("qrc:/"));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
