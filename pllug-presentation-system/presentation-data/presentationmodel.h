#include <QAbstractListModel>
#include <QStringList>

class PresentationModelFields;
class PresentationLoader;
class PresentationModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        PathRole = Qt::UserRole + 1,
        NameRole
    };

    PresentationModel(PresentationLoader* copy, QObject *parent = 0);

    virtual QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    virtual QModelIndex parent(const QModelIndex &index) const;
    virtual int rowCount(const QModelIndex &parent) const;
    virtual int columnCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;

    void setPresentationList();

private:
    PresentationLoader* mPresentationLoader;
    QList <PresentationModelFields*> mPresentationList;
};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
