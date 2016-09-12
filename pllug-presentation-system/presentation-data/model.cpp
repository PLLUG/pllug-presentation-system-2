#include "model.h"

Model::Model(QString name, QString path)
    : mName{name}
    , mPath{path}
{
}

Model::~Model()
{
}

QString Model::name() const
{
    return mName;
}

void Model::setName(const QString &name)
{
    mName = name;
}

QString Model::path() const
{
    return mPath;
}

void Model::setPath(const QString &path)
{
    mPath = path;
}
