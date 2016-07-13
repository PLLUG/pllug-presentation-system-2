#ifndef DOMDOCUMENTDIVIDER_H
#define DOMDOCUMENTDIVIDER_H

#include <QStringList>
#include <QString>
#include <QFile>
#include <QVector>
#include <QtWidgets/QMessageBox>
#include <QDebug>
#include <QDomDocument>

#include "documentimportstrategy.h"
#include "slide.h"
#include "presentationelementfactory.h"
#include "presentation.h"

class DomDocumentDivider : public DocumentImportStrategy
{
public:
    virtual std::unique_ptr<Presentation> import(const QByteArray &inputText) override;

private:
    bool isSeparator(const QDomElement &element);
    bool isHeader(const QDomElement &element);

    QVector<QDomDocument> divideBySeparators(const QDomDocument &htmlDocument);
    QVector<Slide> divideByHeaders(const QVector<QDomDocument> &parts);
    Presentation* divideSlides(const QVector<Slide> &slides);
    QVector<Slide *> divideSlide(const Slide &slide, int elementsNum);
};

#endif // DOMDOCUMENTDIVIDER_H
