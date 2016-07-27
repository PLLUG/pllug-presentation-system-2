#include "presentationelementfactory.h"

#include <QString>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include "presentationelement.h"
#include "header.h"
#include "paragraph.h"
#include "separator.h"

std::unique_ptr<PresentationElement> PresentationElementFactory::create(const QString &html) const
{
    QRegularExpression re("(h[1-6]|hr|p)");
    QRegularExpressionMatch match = re.match(html);
    if(match.hasMatch())
    {
        QString tag = match.captured();
        if(tag == "p")
        {
            return std::make_unique<Paragraph>(html);
        }
        else if(tag[0] == 'h')
        {
            if(tag[1] == 'r')
            {
                return std::make_unique<Separator>(html);
            }
            else
            {
                return std::make_unique<Header>(html);
            }
        }
    }
    else
    {
        return nullptr;
    }
}
