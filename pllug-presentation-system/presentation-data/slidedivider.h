#ifndef SLIDEDIVIDER_H
#define SLIDEDIVIDER_H

#include <QStringList>
#include <QString>
#include <QFile>
#include <QVector>
#include <QtWidgets/QMessageBox>
#include <QDebug>

#include "slide.h"

class SlideDivider
{
public:
    SlideDivider() = delete;
    static QVector<Slide> getSlides(const QString &filename);

private:
    static bool isSeparator(const QString &line);
    static bool isHeader(const QString &line);

    static QVector<QStringList> divideIntoParts(const QStringList &lines);
    static QVector<Slide> divideIntoSlides(const QVector<QStringList> &parts);
    static QVector<Slide> divideSlides(const QVector<Slide> &slides);
    static QVector<Slide> divideSlide(const Slide &slide, int elementsNum);

};

#endif // SLIDEDIVIDER_H
