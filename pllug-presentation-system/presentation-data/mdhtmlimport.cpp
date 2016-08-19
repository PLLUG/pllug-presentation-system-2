#include "mdhtmlimport.h"
#include "pandocrunner.h"
#include "paramsbuilder.h"
#include <QByteArray>
#include <QString>
#include <QFile>
#include <QDebug>
std::unique_ptr<QByteArray> MdHtmlImport::import(const QString &mdFilePath) const
{       
    using namespace PandocSlave;
    ParamsBuilder builder;
    QFile mdFile(mdFilePath);
    QByteArray *md = new QByteArray();
    if(mdFile.open(QFile::ReadOnly))
    {
        md = new QByteArray(mdFile.readAll());
        qDebug() << *md;
    }
    builder.addParam(ParamsBuilder::from, ParamsBuilder::Markdown);
    builder.addParam(ParamsBuilder::to, ParamsBuilder::HTML);
    QString outputFilePath = "C:/Users/JuliaKushniruk/Desktop/output.html";
    builder.addParam(ParamsBuilder::output, outputFilePath);
    builder.addParam(ParamsBuilder::empty, mdFilePath);
    builder.addParam(ParamsBuilder::standalone, "");
    builder.addParam(ParamsBuilder::template_file, "C:/Users/JuliaKushniruk/Desktop/summercamp/template.html");

    PandocRunner pandoc(QString("../pandoc-slave/pandoc/pandoc.exe"), builder.params());
    pandoc.run();

    QFile htmlFile(outputFilePath);
    QByteArray *html = new QByteArray();
    if(htmlFile.open(QFile::ReadOnly))
    {
        html = new QByteArray(htmlFile.readAll());
        qDebug() << *html;
    }
    return std::unique_ptr<QByteArray>(html);
}
