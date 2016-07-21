#include "concretepresentationelementfactory.h"

#include <QString>

#include "presentationelement.h"
#include "header.h"
#include "paragraph.h"
#include "separator.h"

std::unique_ptr<PresentationElement> ConcretePresentationElementFactory::create(const QString &html) const
{
    int position = html.indexOf(">");
    QString tag = html.left(position + 1);
    if (tag == "<hr>")
    {
        return std::make_unique<Separator>(html);
    }
    else if (tag[1] == 'h')
    {
        return std::make_unique<Header>(html);
    }
    else if (tag == "<p>")
    {
        return std::make_unique<Paragraph>(html);
    }
    else
    {
        return nullptr;
    }
}
