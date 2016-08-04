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
    if (parent.column() > 0)
        return 0;

    if(parent.isValid())
    {
        Slide *slide = static_cast<Slide *>(parent.internalPointer());
        if(slide)
        {
            return slide->elementsCount();
        }
        else
        {
            mPresentation->slideCount();
        }
    }
    else
    {
        mPresentation->slideCount();
    }
}

int PresentationModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 1;
}

QVariant PresentationModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid())
    {
        Slide *slide = static_cast<Slide *>(index.internalPointer());
        if(slide)
        {
            switch(role)
            {
            // TODO: Implement actions in these cases.
//            case Roles::X :
//            {
//                return QString::number(element->x());
//            }
//            case Roles::Y :
//            {
//                return QString::number(element->y());
//            }
//            case Roles::Width :
//            {
//                return QString::number(element->width());
//            }
//            case Roles::Height :
//            {
//                return QString::number(element->height());
//            }
            case Roles::Html :
            {
                return slide->toHtml();
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

QVariant PresentationModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal)
    {
        return tr("Slides");
    }
    else
    {
        return QVariant();
    }
}

QModelIndex PresentationModel::index(int row, int column, const QModelIndex &parent) const
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
            return createIndex(row, column, mPresentation->slide(row));
        }
    }
    else
    {
        return createIndex(row, column, mPresentation->slide(row));
    }
}

QModelIndex PresentationModel::parent(const QModelIndex &index) const
{
    // TODO: Implement this method.
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
