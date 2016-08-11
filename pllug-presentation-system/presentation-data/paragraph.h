#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include "textelement.h"

class Paragraph : public TextElement
{
public:
    Paragraph(const QString &html);
};

#endif // PARAGRAPH_H
