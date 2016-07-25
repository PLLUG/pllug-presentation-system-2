#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <memory>

#include <QVector>

#include "slide.h"

/*!
 * \brief The Presentation class is an abstraction for presentation document.
 *
 * Presentation contains all necessary information that describes the presentation document.
 * Presentation also contains ordered list of slides.
 */
class Presentation
{
public:
    Presentation();
    virtual ~Presentation();

    Presentation(const Presentation& other);
    Presentation& operator=(const Presentation& other);

    int slideCount() const;

    void appendSlide(std::unique_ptr<Slide> slide);

    Slide *slide(int index) const;
private:
    QVector<Slide *> mSlideList;
};

#endif // PRESENTATION_H
