#include "header.h"

Header::Header(const QString &html)
    : TextElement(html)
{
    QString substr = html.left(4);
    if(substr[2].isDigit() && (substr[2].digitValue() > 0 || substr[2].digitValue() <= 6))
    {
        mLevel = substr[2].digitValue();
    }
    else
    {
        throw;
    }
}

int Header::level() const
{
    return mLevel;
}
