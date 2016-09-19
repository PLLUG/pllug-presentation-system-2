#ifndef MDPRESENTATIONIMPORT_H
#define MDPRESENTATIONIMPORT_H

#include <QObject>

class QString;
class QByteArray;
class Presentation;

namespace PandocSlave {
    class PandocRunner;
}

class MdPresentationImport: public QObject
{
    Q_OBJECT
public:
    explicit MdPresentationImport(QObject *parent = nullptr);
    void import(const QString &mdFilePath) const;

signals:
    void presentationParsed(Presentation *presentation);

private slots:
    void parsePresentation();

private:
    PandocSlave::PandocRunner *mPandocRunner;
};

#endif // MDPRESENTATIONIMPORT_H
