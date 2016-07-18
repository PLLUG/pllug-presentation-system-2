#ifndef TEXTELEMENT_H
#define TEXTELEMENT_H

#include "presentationelement.h"

#include <QString>

class TextElement : public PresentationElement
{
public:
    TextElement(const QString &html);
    QString tag() const;
};

#endif // TEXTELEMENT_H
