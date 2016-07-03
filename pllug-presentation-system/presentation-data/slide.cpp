#include "slide.h"

#include <QtGlobal>

/*!
 * \brief Public constructor.
 */
Slide::Slide()
{

}

/*!
 * \brief Public destructor.
 */
Slide::~Slide()
{

}

/*!
 * \brief Copy constructor.
 */
Slide::Slide(const Slide &other)
{
    Q_UNUSED(other)
}

/*!
 * \brief Copy assigment.
 */
Slide &Slide::operator=(const Slide &other)
{
    Q_UNUSED(other)

    return  *this;
}

/*!
 * \brief Move constructor.
 */
Slide::Slide(Slide &&other)
{
    Q_UNUSED(other)
}

/*!
 * \brief Move assigment.
 */
Slide &Slide::operator=(Slide &&other)
{
    Q_UNUSED(other)

    return *this;
}
