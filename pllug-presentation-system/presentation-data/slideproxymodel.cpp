#include "slideproxymodel.h"
#include "presentationelement.h"
#include "presentationmodel.h"

SlideProxyModel::SlideProxyModel(QObject *parent):
    QAbstractProxyModel(parent),
    mSlideNumber(0)
{
}

int SlideProxyModel::slideNumber() const
{
    return mSlideNumber;
}

void SlideProxyModel::setSlideNumber(int slideNumber)
{
    if(slideNumber >= 0 && slideNumber < sourceModel()->rowCount())
    {
        beginResetModel();
        mSlideNumber = slideNumber;
        endResetModel();
    }
}

int SlideProxyModel::slideCount() const
{
    return sourceModel()->rowCount();
}

QModelIndex SlideProxyModel::index(int row, int column, const QModelIndex &parent) const
{
    QModelIndex rIndex;
    if (parent.column() > 0)
        return rIndex;

    if(parent.isValid())
    {
        Slide *slide = static_cast<Slide *>(parent.internalPointer());
        if(slide)
        {
            rIndex = createIndex(row, column, slide->element(row));
        }

    }
    else
    {
        Slide *slide = static_cast<Slide *>(sourceModel()->index(mSlideNumber, 0).internalPointer());
        rIndex = createIndex(row, column, slide->element(row));
    }

    return rIndex;
}

QModelIndex SlideProxyModel::parent(const QModelIndex &child) const
{
    // TODO: Implement this method
    Q_UNUSED(child);
    return QModelIndex();
}

int SlideProxyModel::rowCount(const QModelIndex &parent) const
{
    int rCount = 0;
    if(parent.isValid())
    {
        Slide* slide = static_cast<Slide *>(parent.internalPointer());
        if(slide)
        {
            rCount = slide->elementsCount();
        }
        else
        {
            rCount = sourceModel()->rowCount(sourceModel()->index(mSlideNumber, 0));
        }
    }
    else
    {
        rCount = sourceModel()->rowCount(sourceModel()->index(mSlideNumber, 0));
    }
    return rCount;
}

int SlideProxyModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 1;
}

QModelIndex SlideProxyModel::mapFromSource(const QModelIndex &sourceIndex) const
{
    QModelIndex rIndex;
    if(sourceIndex.isValid())
    {
        rIndex = index(sourceIndex.row(),sourceIndex.column());
    }
    return rIndex;
}

QModelIndex SlideProxyModel::mapToSource(const QModelIndex &proxyIndex) const
{
    QModelIndex rIndex;
    if(proxyIndex.isValid())
    {
        rIndex = sourceModel()->index(proxyIndex.row(),proxyIndex.column());
    }
    return rIndex;
}

QVariant SlideProxyModel::data(const QModelIndex &proxyIndex, int role) const
{
    QVariant rData;
    if(proxyIndex.isValid())
    {
        PresentationElement *element = static_cast<PresentationElement *>(proxyIndex.internalPointer());
        if(element)
        {
            switch(role)
            {
            case PresentationModel::Roles::X :
            {
                rData = QString::number(element->x());
                break;
            }
            case PresentationModel::Roles::Y :
            {
                rData = QString::number(element->y());
                break;
            }
            case PresentationModel::Roles::Width :
            {
                rData = QString::number(element->width());
                break;
            }
            case PresentationModel::Roles::Height :
            {
                rData = QString::number(element->height());
                break;
            }
            case PresentationModel::Roles::Html :
            {
                rData = element->toHtml();
                break;
            }
            }
        }
    }
    return rData;
}

QHash<int, QByteArray> SlideProxyModel::roleNames() const
{
    QHash<int, QByteArray> rHash;
    rHash.insert(PresentationModel::Roles::X, "X");
    rHash.insert(PresentationModel::Roles::Y, "Y");
    rHash.insert(PresentationModel::Roles::Width, "Width");
    rHash.insert(PresentationModel::Roles::Height, "Height");
    rHash.insert(PresentationModel::Roles::Html, "Html");
    return rHash;
}

void SlideProxyModel::firstSlide()
{
    setSlideNumber(0);
}

void SlideProxyModel::lastSlide()
{
    setSlideNumber(sourceModel()->rowCount() - 1);
}

void SlideProxyModel::previousSlide()
{
    setSlideNumber(slideNumber() - 1);
}

void SlideProxyModel::nextSlide()
{
    setSlideNumber(slideNumber() + 1);
}
