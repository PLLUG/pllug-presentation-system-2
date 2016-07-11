#include "pandocrunner.h"

#include <QCoreApplication>
#include <QDir>

#include <QDebug>

PandocRunner::PandocRunner(const QStringList &params, QObject* parent):
    QProcess(parent)
  , mParams(params)
  , mContent("")
  , mStatusCode(0)
{
    connect(this, SIGNAL(finished(int)), this, SLOT(finishedProcess(int)));
    connect(this, SIGNAL(readyReadStandardOutput()), this, SLOT(readyReadOutput()));
    connect(this, SIGNAL(readyReadStandardError()), this, SLOT(readyReadError()));
}

QString PandocRunner::run()
{
    QString projFolder = QCoreApplication::applicationDirPath();
    QString mPandocExePath = QDir(projFolder).filePath("3rdparty/pandoc/windows/pandoc.exe");

    if (mParams.isEmpty())
    {
        mStatusCode = -1;
        return "Empty parameter list!";
    }

    start(mPandocExePath, mParams);
    waitForFinished(-1);

    return mContent;
}

int PandocRunner::statusCode() const
{
    return mStatusCode;
}

void PandocRunner::setParams(const QStringList &params)
{
    mParams = params;
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
    mContent = QString(readAllStandardError());
}

QString PandocRunner::content()
{
    return mContent;
}
