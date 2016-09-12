#include "presentationmodelloader.h"
#include "presentationmodel.h"
#include "presentationmodelfields.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

PresentationLoader::PresentationLoader(QObject *parent)
    : QObject (parent),
      mPresentationModel{new PresentationModel(this)}
{    
}

void PresentationLoader::load()
{
    qDeleteAll(mPresentationList);
    mPresentationList.clear();

    QFile file(mPathToFile);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug("Error: Could not open the file");
    }
    QByteArray data = file.readAll();
    file.close();

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(data, &err);
    if (err.error == QJsonParseError::NoError && doc.isObject())
    {
        QJsonObject o = doc.object();
        QJsonValue value = o.value("presentations");
        QJsonArray presentationArray = value.toArray();
        for (int i = 0; i < presentationArray.count(); i++)
        {
            QJsonValue nextValue = presentationArray.at(i);
            QJsonObject nextObject = nextValue.toObject();
            PresentationModelFields *presentation = parsePresentation(nextObject);
            if (presentation)
            {
                mPresentationList.append(presentation);
            }
        }
      //  mPresentationModel->setPresentationList();
    }
}

QList<PresentationModelFields *> PresentationLoader::getList() const
{
    return mPresentationList;
}

PresentationLoader::~PresentationLoader()
{
    qDeleteAll(mPresentationList);
}

void PresentationLoader::setFileName(const QString &pathToFile)
{
    mPathToFile = pathToFile;
}

QList <PresentationModelFields*> PresentationLoader::presentations() const
{
    return  mPresentationList;
}

PresentationModelFields *PresentationLoader::parsePresentation(const QJsonObject &obj)
{
    PresentationModelFields *rPresentation {};

    QString path = obj.value("path").toString();
    QString name = obj.value("name").toString();

    if (!path.isEmpty())
    {
        rPresentation = new PresentationModelFields(path, name);
    }

    return  rPresentation;
}

PresentationModel *PresentationLoader::presentationModel() const
{
    return mPresentationModel;
}

void PresentationLoader::setPresentationModel(PresentationModel *presentationModel)
{
    mPresentationModel = presentationModel;
}
