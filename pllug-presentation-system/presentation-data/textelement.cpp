#include "textelement.h"

TextElement::TextElement(const QString &html)
    : PresentationElement(html)
{ 
}

QString TextElement::tag() const
{
    int position = mContent.indexOf(">");
    return mContent.left(position + 1);
}
