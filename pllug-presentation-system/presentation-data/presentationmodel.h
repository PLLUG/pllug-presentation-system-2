#include <QAbstractListModel>
#include <QStringList>

class PresentationModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        PathRole = Qt::UserRole + 1,
        NameRole
    };

    PresentationModel(QObject *parent = 0);

    virtual int rowCount(const QModelIndex &parent) const;
    virtual int columnCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void debug();
    Q_INVOKABLE void add();

private:
    QStringList mPresentation;
};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
