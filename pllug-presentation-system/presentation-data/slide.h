#ifndef SLIDE_H
#define SLIDE_H

#include <memory>
#include <QVector>

#include "presentationelement.h"

/*!
 * \brief The Slide class represents single slide from presentation.
 *
 * Slide contains unordered list of elements that should be displayed on it.
 */
class Slide
{
public:
    Slide();
    virtual ~Slide();

    Slide(const Slide& other);
    Slide& operator=(const Slide& other);

    int elementsCount() const;

    void addElement(std::unique_ptr<PresentationElement> element);

    PresentationElement* element(int index) const;

    QString toHtml() const;

private:
    QVector<PresentationElement *> mElementsList;
};

#endif // SLIDE_H
