#include "presentationmodelloader.h"
#include "presentationmodel.h"

#include <QFile>

PresentationLoader::PresentationLoader(QObject *parent)
    : QObject (parent),
      mPresentationModel{new PresentationModel(this)}
{
}


void PresentationLoader::setFileName(const QString &pathToFile)
{
    mPath = pathToFile;
    load();
}

void PresentationLoader::load()
{
}

PresentationModel *PresentationLoader::presentationModel() const
{
    return mPresentationModel;
}

void PresentationLoader::setPresentationModel(PresentationModel *presentationModel)
{
    mPresentationModel = presentationModel;
}
