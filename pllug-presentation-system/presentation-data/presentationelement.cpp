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

int PresentationElement::x() const
{
    return 1;
}

int PresentationElement::y() const
{
    return 1;
}

int PresentationElement::width() const
{
    return 1;
}

int PresentationElement::height() const
{
    return 1;
}

QString PresentationElement::toHtml() const
{
    return mContent;
}
