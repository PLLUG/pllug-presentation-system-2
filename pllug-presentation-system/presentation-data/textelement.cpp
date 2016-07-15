#include "textelement.h"

TextElement::TextElement(const QString &html)
    : mContent{html}
{ 
}

QString TextElement::toHtml() const
{
    return mContent;
}

QString TextElement::tag() const
{
    int position = mContent.indexOf(">");
    return mContent.left(position + 1);
}
