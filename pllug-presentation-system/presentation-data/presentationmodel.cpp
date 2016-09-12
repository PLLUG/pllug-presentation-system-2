#include "presentationmodel.h"
#include "presentationmodelfields.h"
#include "presentationmodelloader.h"
#include <QFile>
#include <QDebug>

PresentationModel::PresentationModel(PresentationLoader* copy, QObject *parent):
    QAbstractListModel(parent)
{
//    mPresentationList.append("C:\Users\Downloads\PresentationTwo");
    mPresentationLoader = copy;
    mPresentationList = mPresentationLoader->getList();
}

int PresentationModel::rowCount(const QModelIndex &parent) const
{
    if (parent.column() > 0)
        return 0;
    return mPresentationList.size();
}

int PresentationModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 1;
}

QVariant PresentationModel::data(const QModelIndex &index, int role) const
{
    QVariant data;
    if (!index.isValid()) {
        return QVariant();
    }

    PresentationModelFields* presentation = mPresentationList[index.row()];

    switch (role) {
    case PathRole:
        data = presentation->path();
        break;
    case NameRole:
        data = presentation->name();
        break;
    default:
        break;
    }
    return data;
}

QHash<int, QByteArray> PresentationModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[PathRole] = "path";
    roles[NameRole] = "name";
    return roles;
}

void PresentationModel::setPresentationList()
{
    //mPresentationList = mPresentationLoader->getList();
}

QModelIndex PresentationModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return createIndex(row, column);
}

QModelIndex PresentationModel::parent(const QModelIndex &index) const
{
    Q_UNUSED(index)
    return QModelIndex();
}

