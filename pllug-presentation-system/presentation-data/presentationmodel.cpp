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
    return mPresentation->slideCount();
}

int PresentationModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant PresentationModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int column = index.column();

    if (column == 1 && (index.parent().row() < mPresentation->slideCount()))
    {
        PresentationElement *element = mPresentation->slide(index.parent().row())->element(row);

        switch(role)
        {
        case Roles::X :
        {
            return element->x();
        }
        case Roles::Y :
        {
            return element->y();

        }
        case Roles::Width :
        {
            return element->width();

        }
        case Roles::Height :
        {
            return element->height();

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
