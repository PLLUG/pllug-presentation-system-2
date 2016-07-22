#ifndef PRESENTATIONMODEL_H
#define PRESENTATIONMODEL_H

#include <QAbstractItemModel>
#include <QObject>

#include "slide.h"
#include "presentation.h"

class PresentationModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit PresentationModel(QObject *parent = nullptr);

    void setPresentation(Presentation *presentation);

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual int columnCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    enum Roles
    {
        X, Y, Width, Height, Html
    };

private:
    Presentation *mPresentation;
};

#endif // PRESENTATIONMODEL_H
