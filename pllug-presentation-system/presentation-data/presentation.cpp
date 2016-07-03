#include "presentation.h"

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

}

/*!
 * \brief Copy constructor.
 */
Presentation::Presentation(const Presentation &other)
{
    Q_UNUSED(other)
}

/*!
 * \brief Copy assigment.
 */
Presentation& Presentation::operator=(const Presentation &other)
{
    Q_UNUSED(other)

    return *this;
}

/*!
 * \brief Move constructor.
 */
Presentation::Presentation(Presentation&& other)
{
    Q_UNUSED(other)
}

/*!
 * \brief Move assigment.
 */
Presentation &Presentation::operator=(Presentation &&other)
{
    Q_UNUSED(other)

    return *this;
}


