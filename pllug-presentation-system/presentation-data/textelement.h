#ifndef TEXTELEMENT_H
#define TEXTELEMENT_H

#include "presentationelement.h"

#include <QString>

class TextElement : public PresentationElement
{
public:
    TextElement(const QString &html);
    QString toHtml() const;
    QString tag() const;
private:
    QString mContent;
};

#endif // TEXTELEMENT_H
