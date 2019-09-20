#ifndef PRESENTATIONCONTROLLER_H
#define PRESENTATIONCONTROLLER_H

#include <QObject>
#include <QString>

class Presentation;
class PresentationModel;
class MdPresentationImport;

class PresentationController : public QObject
{
    Q_OBJECT
public:
    explicit PresentationController(QObject *parent = 0);

    Q_INVOKABLE PresentationModel *presentationModel() const;
    Q_INVOKABLE void importPresentation(const QString &presentationPath);

private slots:
    void getNewPresentation(Presentation *presentation);

private:
    PresentationModel *mPresentationModel;
};

#endif // PRESENTATIONCONTROLLER_H
