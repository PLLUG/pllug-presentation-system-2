#ifndef PRESENTATIONELEMENT_H
#define PRESENTATIONELEMENT_H

/*!
 * \brief The PresentationElement class represents single element that could be placed
 * on presentation slide.
 */
#include <QString>

class PresentationElement
{
public:
    PresentationElement();
    PresentationElement(const QString &html);
    virtual ~PresentationElement() = 0;

    QString toHtml() const;

protected:
    QString mContent;
};

#endif // PRESENTATIONELEMENT_H
