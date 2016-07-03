#ifndef SLIDE_H
#define SLIDE_H

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

    Slide(Slide&& other);
    Slide& operator=(Slide&& other);
};

#endif // SLIDE_H
