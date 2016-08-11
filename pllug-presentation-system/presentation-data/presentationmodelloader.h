#ifndef PRESENTATIONMODELLOADER_H
#define PRESENTATIONMODELLOADER_H

#include <QObject>
#include <QStringList>

class PresentationModel;
class PresentationLoader : public QObject
{
    Q_OBJECT

public:
    explicit PresentationLoader(QObject *parent = nullptr);


       void setFileName(const QString &pathToFile);

       PresentationModel *presentationModel() const;
       void setPresentationModel(PresentationModel *presentationModel);

 private:
       void load();

       PresentationModel* mPresentationModel;
       QString mPath;

};

#endif // PRESENTATIONMODELLOADER_H
