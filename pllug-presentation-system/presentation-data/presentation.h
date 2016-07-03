#ifndef PRESENTATION_H
#define PRESENTATION_H

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

    Presentation(Presentation&& other);
    Presentation& operator=(Presentation&& other);
};

#endif // PRESENTATION_H
