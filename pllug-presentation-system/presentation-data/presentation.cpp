#include "presentation.h"

#include <utility>
#include <algorithm>
#include <QtGlobal>

/*!
 * \brief Public constructor.
 */
Presentation::Presentation()
{
}

/*!
 * \brief Public destructor.
 */
Presentation::~Presentation()
{
    qDeleteAll(mSlideList);
}

/*!
 * \brief Copy constructor.
 */
Presentation::Presentation(const Presentation &other)
{
    for (const auto &slide: other.mSlideList)
    {
        Slide *newSlide = new Slide(*slide);
        mSlideList.push_back(newSlide);
    }
}

/*!
 * \brief Copy assigment.
 */
Presentation& Presentation::operator=(const Presentation &other)
{
    Presentation tmp(other);
    mSlideList.swap(tmp.mSlideList);
    return *this;
}

/*!
 * \brief Returns number of slides in presentation.
 * \return Number of slides.
 */
int Presentation::slideCount() const
{
    return mSlideList.size();
}

/*!
 * \brief Appends slide to the end of presentation. Presentation takes ownership of slide.
 * \param slide Slide to be added.
 */
void Presentation::appendSlide(std::unique_ptr<Slide> slide)
{
    mSlideList.push_back(slide.release());
}

Slide *Presentation::slide(int index) const
{
    return mSlideList[index];
}

