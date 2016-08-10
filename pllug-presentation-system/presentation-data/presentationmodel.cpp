#include "presentationmodel.h"
#include <QFile>

PresentationModel::PresentationModel(QObject *parent):
    QAbstractListModel(parent)
{
}

int PresentationModel::rowCount(const QModelIndex &parent) const
{
    if (parent.column() > 0)
        return 0;
    return mPresentation.size();
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
        return data;
    }

    switch (role) {
    case PathRole:
        data = mPresentation[index.row()];
        return data;
    case NameRole:
        data = QFile(mPresentation[index.row()]).fileName();
        return data;
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

void PresentationModel::add()
{
    beginInsertRows(QModelIndex(), mPresentation.size(), mPresentation.size());
    mPresentation.append("new");
    endInsertRows();
    mPresentation[0] = QString("Size: %1").arg(mPresentation.size());
    QModelIndex index = createIndex(0, 0, static_cast<void *>(0));
    emit dataChanged(index, index);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
