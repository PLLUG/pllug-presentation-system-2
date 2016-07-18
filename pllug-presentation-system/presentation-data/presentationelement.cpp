#include "presentationelement.h"

PresentationElement::~PresentationElement()
{

}

PresentationElement::PresentationElement()
{
}

PresentationElement::PresentationElement(const QString &html)
    : mContent{html}
{
}

QString PresentationElement::toHtml() const
{
    return mContent;
}
