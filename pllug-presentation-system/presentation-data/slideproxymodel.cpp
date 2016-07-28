#include "slideproxymodel.h"
#include "presentationelement.h"
#include "presentationmodel.h"

SlideProxyModel::SlideProxyModel(QObject *parent):
    QAbstractProxyModel(parent)
{
}

int SlideProxyModel::slideNumber() const
{
    return mSlideNumber;
}

void SlideProxyModel::setSlideNumber(int slideNumber)
{
    mSlideNumber = slideNumber;
}

QModelIndex SlideProxyModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.column() > 0)
        return QModelIndex();

    if(parent.isValid())
    {
        Slide *slide = static_cast<Slide *>(parent.internalPointer());
        if(slide)
        {
            return createIndex(row, column, slide->element(row));
        }
        else
        {
            return QModelIndex();
        }
    }
    else
    {
        Slide *slide = static_cast<Slide *>(sourceModel()->index(mSlideNumber,0).internalPointer());
        return createIndex(row, column, slide->element(row));
    }
}

QModelIndex SlideProxyModel::parent(const QModelIndex &child) const
{
    // TODO: Implement this method
    return QModelIndex();
}

int SlideProxyModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
    {
        Slide* slide = static_cast<Slide *>(parent.internalPointer());
        if(slide)
        {
            return slide->elementsCount();
        }
        else
        {
            return sourceModel()->rowCount(sourceModel()->index(mSlideNumber, 0));
        }
    }
    else
    {
        return sourceModel()->rowCount(sourceModel()->index(mSlideNumber, 0));
    }
}

int SlideProxyModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QModelIndex SlideProxyModel::mapFromSource(const QModelIndex &sourceIndex) const
{
    return index(sourceIndex.row(),sourceIndex.column());
}

QModelIndex SlideProxyModel::mapToSource(const QModelIndex &proxyIndex) const
{
    return sourceModel()->index(proxyIndex.row(),proxyIndex.column());
}

QVariant SlideProxyModel::data(const QModelIndex &proxyIndex, int role) const
{
    if(proxyIndex.isValid())
    {
        PresentationElement *element = static_cast<PresentationElement *>(proxyIndex.internalPointer());
        if(element)
        {
            switch(role)
            {
            case PresentationModel::Roles::X :
            {
                return QString::number(element->x());
            }
            case PresentationModel::Roles::Y :
            {
                return QString::number(element->y());
            }
            case PresentationModel::Roles::Width :
            {
                return QString::number(element->width());
            }
            case PresentationModel::Roles::Height :
            {
                return QString::number(element->height());
            }
            case PresentationModel::Roles::Html :
            {
                return element->toHtml();
            }
            default:
            {
                return QVariant();
            }
            }
        }
        else
        {
            return QVariant();
        }
    }
    else
    {
        return QVariant();
    }
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
