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
    if (tag[1] == 'h')
    {
        return std::unique_ptr<Header>(new Header(html));
    }
    else if (tag == "<p>")
    {
        return std::unique_ptr<Paragraph>(new Paragraph(html));
    }
    else if (tag == "<hr>")
    {
        return std::unique_ptr<Separator>(new Separator(html));
    }
    else
    {
        return nullptr;
    }
}
