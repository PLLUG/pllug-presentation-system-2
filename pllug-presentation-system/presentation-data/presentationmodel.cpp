#include "presentationmodel.h"
#include <QFile>
#include <QDebug>

PresentationModel::PresentationModel(QObject *parent):
    QAbstractListModel(parent)
{
//    mPresentation.append("C:\Users\Downloads\PresentationOne");
//    mPresentation.append("C:\Users\Downloads\PresentationTwo");
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
        return QVariant();
    }

    switch (role) {
    case PathRole:
        data = mPresentation[index.row()];
        break;
    case NameRole:
        data = QFile(mPresentation[index.row()]).fileName();
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

void PresentationModel::add()
{
    beginInsertRows(QModelIndex(), mPresentation.size(), mPresentation.size());
    mPresentation.append("new");
    endInsertRows();
    mPresentation[0] = QString("Size: %1").arg(mPresentation.size());
    QModelIndex index = createIndex(0, 0, static_cast<void *>(0));
    emit dataChanged(index, index);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

void PresentationModel::debug()
{
    qDebug() << "It's alive!";
}
