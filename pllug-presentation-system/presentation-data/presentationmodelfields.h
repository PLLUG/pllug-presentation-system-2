#ifndef PRESENTATIONMODELFIELDS_H
#define PRESENTATIONMODELFIELDS_H

#include <QString>

class PresentationModelFields
{
public:

    PresentationModelFields(QString path, QString name);

    ~PresentationModelFields();

    QString name() const;
    void setName(const QString &name);

    QString path() const;
    void setPath(const QString &path);

private:
    QString mName;
    QString mPath;
};

#endif // PRESENTATIONMODELFIELDS_H
