#include "presentationmodeltest.h"

PresentationModelTest::PresentationModelTest(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant PresentationModelTest::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex PresentationModelTest::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex PresentationModelTest::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int PresentationModelTest::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int PresentationModelTest::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant PresentationModelTest::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
