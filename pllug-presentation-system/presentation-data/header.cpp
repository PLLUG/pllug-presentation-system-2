#include "header.h"

Header::Header(const QString &html)
    : TextElement(html)
{
    QString substr = html.left(4);
    if(substr[3].isDigit() && (substr[3].digitValue() > 0 || substr[3].digitValue() <= 6))
    {
        mLevel = substr[3].digitValue();
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
