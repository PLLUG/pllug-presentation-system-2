#ifndef SLIDEPROXYMODEL_H
#define SLIDEPROXYMODEL_H

#include <QObject>
#include <QAbstractProxyModel>
#include <QItemSelection>
#include <QHash>

class Slide;

class SlideProxyModel : public QAbstractProxyModel
{
    Q_OBJECT
public:
    explicit SlideProxyModel(QObject *parent = Q_NULLPTR);

    Q_INVOKABLE int slideNumber() const;
    Q_INVOKABLE void setSlideNumber(int slideNumber);

    Q_INVOKABLE int slideCount() const;

    Q_INVOKABLE virtual QModelIndex index(int row, int column,
                                          const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE virtual QModelIndex parent(const QModelIndex &child) const override;
    Q_INVOKABLE virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE virtual QModelIndex mapToSource(const QModelIndex &proxyIndex) const override;
    Q_INVOKABLE virtual QModelIndex mapFromSource(const QModelIndex &sourceIndex) const override;
    virtual QVariant data(const QModelIndex &proxyIndex, int role = Qt::DisplayRole) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void firstSlide();
    Q_INVOKABLE void lastSlide();
    Q_INVOKABLE void previousSlide();
    Q_INVOKABLE void nextSlide();

    void dataChangedHandler();

private:
    int mSlideNumber;
};

#endif // SLIDEPROXYMODEL_H
