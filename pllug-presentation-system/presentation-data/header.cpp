#include "header.h"

#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QDebug>

Header::Header(const QString &html)
    : TextElement(html)
{
    QRegularExpression re("h[1-6]");
    QRegularExpressionMatch match = re.match(html);
    if(match.hasMatch())
    {
        QString cap = match.captured();
        mLevel = cap[1].digitValue();
    }
    else
    {
        mLevel = 1;
        qWarning() << "Warning: Invalid header level.";
    }
}

int Header::level() const
{
    return mLevel;
}
