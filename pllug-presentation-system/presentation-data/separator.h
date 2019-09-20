#ifndef SEPARATOR_H
#define SEPARATOR_H

#include "presentationelement.h"
class QString;

class Separator : public PresentationElement
{
public:
    Separator(const QString &html);
};

#endif // SEPARATOR_H
