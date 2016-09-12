#ifndef PRESENTATIONLOADER_H
#define PRESENTATIONLOADER_H

#include <QObject>
#include <QStringList>

class PresentationModel;
class PresentationModelFields;
class QJsonObject;

class PresentationLoader : public QObject
{
    Q_OBJECT

public:
    explicit PresentationLoader(QObject *parent = nullptr);
    ~PresentationLoader();

    PresentationModel *presentationModel() const;
    void setFileName(const QString &pathToFile);
    void setPresentationModel(PresentationModel *presentationModel);

    QList <PresentationModelFields*> presentations() const;
    void load();
    QList <PresentationModelFields*> getList() const;

private:

    PresentationModelFields *parsePresentation(const QJsonObject &obj);

    QString mPathToFile;
    QList <PresentationModelFields*> mPresentationList;
    PresentationModel* mPresentationModel;

};

#endif // PRESENTATIONLOADER_H
