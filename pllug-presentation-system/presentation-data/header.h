#ifndef HEADER_H
#define HEADER_H

#include "textelement.h"


class Header : public TextElement
{
public:
    Header(const QString &html);

    int level() const;

private:
    int mLevel;
};

#endif // HEADER_H
