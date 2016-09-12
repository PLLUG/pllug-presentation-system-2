#include "presentationmodelfields.h"
#include "presentationmodel.h"
#include <QFile>

PresentationModelFields::PresentationModelFields(QString path, QString name)
    : mPath{path}
    , mName{name}
{
}

PresentationModelFields::~PresentationModelFields()
{
}

QString PresentationModelFields::name() const
{
    return QFile(mPath).fileName();
}

QString PresentationModelFields::path() const
{
    return mPath;
}

void PresentationModelFields::setPath(const QString &path)
{
    mPath = path;
}
