#include "slidedivider.h"

const int C_MAX_NUM_OF_ELEMENTS = 6;

QVector<Slide> SlideDivider::getSlides(const QString &filename)
{
    QFile presentation(filename);
    QStringList lines;

    if (presentation.open(QFile::ReadOnly))
    {
        while(!presentation.atEnd())
        {
            lines.append(presentation.readLine());
        }
    }
    else
    {
        QMessageBox::critical(0, "Error", "Could not open file: " + filename);
    }

    QVector<QStringList> parts = divideIntoParts(lines);
    QVector<Slide> undividedSlides = divideIntoSlides(parts);
    return  divideSlides(undividedSlides);
}

QVector<QStringList> SlideDivider::divideIntoParts(const QStringList &lines)
{
    QVector<QStringList> rParts;
    QStringList currentPart;

    for (const QString &line: lines)
    {
        if (isSeparator(line))
        {
            rParts.push_back(currentPart);
            currentPart.erase(currentPart.begin(), currentPart.end());
        }
        else
        {
            currentPart.append(line);
        }
    }
    if (!currentPart.isEmpty())
    {
        rParts.push_back(currentPart);
    }

    return rParts;
}

QVector<Slide> SlideDivider::divideIntoSlides(const QVector<QStringList> &parts)
{
    QVector<Slide> rSlides;
    Slide currentSlide;

    for (const QStringList &part: parts)
    {
        for (const QString &line: part)
        {
            if (isHeader(line))
            {
                if (currentSlide.elementsCount() != 0)
                {
                    rSlides.push_back(currentSlide);
                }
                currentSlide = Slide(line);
            }
            else
            {
                currentSlide.addElement(line);
            }
        }
    }
    if (currentSlide.elementsCount() != 0)
    {
        rSlides.push_back(currentSlide);
    }

    return rSlides;
}

QVector<Slide> SlideDivider::divideSlides(const QVector<Slide> &slides)
{
    QVector<Slide> rDividedSlides;

    for (const Slide &slide: slides)
    {
        QVector<Slide> slides = divideSlide(slide, C_MAX_NUM_OF_ELEMENTS);
        for (Slide slide: slides)
        {
            rDividedSlides.push_back(slide);
        }
    }
    return rDividedSlides;
}

QVector<Slide> SlideDivider::divideSlide(const Slide &slide, int elementsNum)
{
    // FIXME: We should be able to get slide elements, including the title. (Header #1)
    // I also supposed that there is a constructor, which takes a QString parameter to represent the title.
    QVector<Slide> rSmallerSlides;
    Slide currentSlide(slide.title());

    for (int i = 0; i < slide.elementsCount(); ++i)
    {
        if (currentSlide.elementsCount() == elementsNum)
        {
            rSmallerSlides.push_back(currentSlide);
            currentSlide = Slide(slide.title());
        }
        currentSlide.addElement(slide.getElement(i));
    }
    if (currentSlide.elementsCount() != 0)
    {
        rSmallerSlides.push_back(currentSlide);
    }

    return rSmallerSlides;
}

bool SlideDivider::isSeparator(const QString &line)
{
    QString substr = line.left(3);
    return ((substr == "---") || (substr == "***") || (substr == "___"));
}

bool SlideDivider::isHeader(const QString &line)
{
    return ((line.size() != 0) && (line[0] == '#'));
}
