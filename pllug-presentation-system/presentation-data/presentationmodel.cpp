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
        return 0;
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
            PresentationElement *element = slide->element(index.row());
            switch(role)
            {
            case Roles::X :
            {
                return QString::number(element->x());
            }
            case Roles::Y :
            {
                return QString::number(element->y());
            }
            case Roles::Width :
            {
                return QString::number(element->width());
            }
            case Roles::Height :
            {
                return QString::number(element->height());
            }
            case Roles::Html :
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
           return QString::number(index.row());
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
