#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "presentationmodel.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    PresentationModel data;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("slideModel", &data);
    engine.addImportPath(QStringLiteral("qrc:/"));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
