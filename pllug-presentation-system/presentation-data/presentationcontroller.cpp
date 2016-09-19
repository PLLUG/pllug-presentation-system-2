#include "presentationcontroller.h"
#include "mdpresentationimport.h"
#include "presentationmodel.h"
#include "presentation.h"

#include <QDebug>
#include <QScopedPointer>

PresentationController::PresentationController(QObject *parent) :
    QObject(parent)
  , mPresentationModel {new PresentationModel(this)}
{
    mPresentationModel->setPresentation(new Presentation());
}

PresentationModel *PresentationController::presentationModel() const
{
    return mPresentationModel;
}

void PresentationController::importPresentation(const QString &presentationPath)
{
    auto mMdPresentationImport = new MdPresentationImport(this);
    connect(mMdPresentationImport, &MdPresentationImport::presentationParsed,
            this, &PresentationController::getNewPresentation, Qt::UniqueConnection);
    mMdPresentationImport->import(presentationPath);
}

void PresentationController::getNewPresentation(Presentation *presentation)
{
    QScopedPointer<Presentation> oldPresentation (mPresentationModel->presentation());
    mPresentationModel->setPresentation(presentation);
    delete sender();
}
