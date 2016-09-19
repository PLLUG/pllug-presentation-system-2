#include "presentationmodel.h"

PresentationModel::PresentationModel(QObject *parent)
    :QAbstractItemModel(parent)
{
}

void PresentationModel::setPresentation(Presentation *presentation)
{
    mPresentation = presentation;
}

int PresentationModel::rowCount(const QModelIndex &parent) const
{
    int rRowCount = 0;
    if (parent.column() > 0)
        return rRowCount;

    if(parent.isValid())
    {
        Slide *slide = static_cast<Slide *>(parent.internalPointer());
        if(slide)
        {
            rRowCount = slide->elementsCount();
        }
        else
        {
            rRowCount = mPresentation->slideCount();
        }
    }
    else
    {
        rRowCount = mPresentation->slideCount();
    }

    return rRowCount;
}

int PresentationModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 1;
}

QVariant PresentationModel::data(const QModelIndex &index, int role) const
{
    QVariant rData;
    if(index.isValid())
    {
        Slide *slide = static_cast<Slide *>(index.internalPointer());
        if(slide)
        {
            switch(role)
            {
            //            case Roles::X :
            //            {
            //                rData = QString::number(element->x());
            //                break;
            //            }
            //            case Roles::Y :
            //            {
            //                rData = QString::number(element->y());
            //                break;
            //            }
            //            case Roles::Width :
            //            {
            //                rData = QString::number(element->width());
            //                break;
            //            }
            //            case Roles::Height :
            //            {
            //                rData = QString::number(element->height());
            //                break;
            //            }
            case Roles::Html :
            {
                rData = slide->toHtml();
                break;
            }
            }
        }
    }
    return rData;
}

QVariant PresentationModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_UNUSED(section);
    Q_UNUSED(role);
    QVariant rHeaderData;
    if(orientation == Qt::Horizontal)
    {
        rHeaderData = tr("Slides");
    }
    return rHeaderData;
}

QModelIndex PresentationModel::index(int row, int column, const QModelIndex &parent) const
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
        else
        {
            rIndex = createIndex(row, column, mPresentation->slide(row));
        }
    }
    else
    {
        rIndex = createIndex(row, column, mPresentation->slide(row));
    }
    return rIndex;
}

QModelIndex PresentationModel::parent(const QModelIndex &index) const
{
    // TODO: Implement this method.
    Q_UNUSED(index);
    return QModelIndex();
}

QHash<int, QByteArray> PresentationModel::roleNames() const
{
    QHash<int, QByteArray> rHash;
    rHash.insert(Roles::X, "X");
    rHash.insert(Roles::Y, "Y");
    rHash.insert(Roles::Width, "Width");
    rHash.insert(Roles::Height, "Height");
    rHash.insert(Roles::Html, "Html");
    return rHash;
}

Presentation *PresentationModel::presentation() const
{
    return mPresentation;
}
