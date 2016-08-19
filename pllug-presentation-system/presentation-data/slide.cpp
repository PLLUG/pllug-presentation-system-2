#include "slide.h"
#include <QDebug>
#include <QtGlobal>
#include "separator.h"
#include "presentationelementfactory.h"

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
    qDeleteAll(mElementsList);
}

/*!
 * \brief Copy constructor.
 */
Slide::Slide(const Slide &other)
{
    *this = other;
}

/*!
 * \brief Copy assigment.
 */
Slide &Slide::operator=(const Slide &other)
{
    qDeleteAll(mElementsList);
    PresentationElementFactory factory;
    for(auto elem: other.mElementsList)
    {
        mElementsList.append(factory.create(elem->toHtml()).release());
    }
    return  *this;
}


/*!
 * \brief Returns number of elements on the slide.
 * \return Number of elements.
 */
int Slide::elementsCount() const
{
    return mElementsList.size();
}

/*!
 * \brief Places presentation element on a slide.
 * \param element Element to be placed.
 */
void Slide::addElement(std::unique_ptr<PresentationElement> element)
{
    mElementsList.append(element.release());
}

PresentationElement *Slide::element(int index) const
{
    PresentationElement *rElement {};
    if(index >= 0 && index < mElementsList.count())
    {
        rElement = mElementsList[index];
    }
    else
    {
        qWarning() << "Warning: Invalid slide element index.";
        rElement = new Separator("<hr />");
    }
    return rElement;
}

QString Slide::toHtml() const
{
    QString rHtml;
    for(int i = 0; i < elementsCount(); ++i)
    {
        rHtml.append(element(i)->toHtml());
    }
    return rHtml;
}
