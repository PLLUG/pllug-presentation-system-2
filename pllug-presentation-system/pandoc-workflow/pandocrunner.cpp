#include "pandocrunner.h"

#include <QString>
#include <QStringList>
#include <QCoreApplication>
#include <QDir>


PandocRunner::PandocRunner(QObject* parent):
    QProcess(parent)
  , mContent("")
  , mError("")
  , mStatusCode(0)
{
    QString projFolder = QCoreApplication::applicationDirPath();
    mPandocExePath = QDir(projFolder).filePath("3rdparty/pandoc/windows/pandoc.exe");

    mMetaEnum = QMetaEnum::fromType<PandocFormat>();

    connect(this, SIGNAL(finished(int)), this, SLOT(finishedProcess(int)));
    connect(this, SIGNAL(readyReadStandardOutput()), this, SLOT(readyReadOutput()));
    connect(this, SIGNAL(readyReadStandardError()), this, SLOT(readyReadError()));
}

QString PandocRunner::run(PandocFormat from, PandocFormat to, const QString &file)
{

    QStringList params = buildParams(from, to, file);

    start(mPandocExePath, params);

    waitForFinished(-1);

    if (mStatusCode == 0)
    {
        return mContent;
    }
    else
    {
        return mError;
    }
}

int PandocRunner::statusCode() const
{
    return mStatusCode;
}

void PandocRunner::finishedProcess(int exitCode)
{
    mStatusCode = exitCode;
}

void PandocRunner::readyReadOutput()
{
    mContent = QString(readAllStandardOutput());
}

void PandocRunner::readyReadError()
{
    mError = QString(readAllStandardError());
}

QString PandocRunner::content()
{
    return mContent;
}

QString PandocRunner::error()
{
    return mError;
}

QStringList PandocRunner::buildParams(PandocFormat from, PandocFormat to, const QString &file) const
{
    QStringList params;

    if (!file.isEmpty())
    {
        params << file;
    }

    params << QString("-f") << QString(mMetaEnum.valueToKey(from)).toLower();
    params << QString("-t") << QString(mMetaEnum.valueToKey(to)).toLower();

    return params;
}
