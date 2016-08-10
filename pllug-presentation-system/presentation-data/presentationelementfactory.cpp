#include "presentationelementfactory.h"
#include "presentationelement.h"
#include "header.h"
#include "paragraph.h"
#include "separator.h"

#include <QString>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

std::unique_ptr<PresentationElement> PresentationElementFactory::create(const QString &html) const
{
    QRegularExpression re("(h[1-6]|hr|p)");
    QRegularExpressionMatch match = re.match(html);
    std::unique_ptr<PresentationElement> rElement(new Separator("<hr />"));
    if(match.hasMatch())
    {
        QString tag = match.captured();
        if(tag == "p")
        {
            rElement.reset(new Paragraph(html));
        }
        else if(tag[0] == 'h')
        {
            if(tag[1] == 'r')
            {
                rElement.reset(new Separator(html));
            }
            else
            {
                rElement.reset(new Header(html));
            }
        }
    }
    return rElement;
}
