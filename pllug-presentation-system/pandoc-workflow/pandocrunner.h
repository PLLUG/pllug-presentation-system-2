#ifndef PANDOCRUNNER_H
#define PANDOCRUNNER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QProcess>

/*!
 * \brief The PandocRunner class provides functionality
 * to run pandoc utility with specified parameters
 *
 * Usage:
 * \code{.cpp}
 * QStringList params;                      // Command line parameters for pandoc
 * params << "path/to/file/input.md";       // Full path to input file
 * params << "-f" << "markdown";            // Other parameters
 * params << "-t" << "html";                // Other parameters
 *
 * PandocRunner runner(params);             // Create instance runner
 * QString content = runner.run();          // Method run() return output content or error
 * if (runner.statusCode != 0)
 * {
 *      qDebug() << "ERROR:" << content;    // In this case content holds error
 * }
 * else
 * {
 *      qDebug() << content;                // content holds converted string
 * }
 *
 * // We can change parameters and rerun pandoc
 * params.clear();
 * params << "path/to/file/input.md";
 * params << "-f" << "markdown";
 * params << "-t" << "latex";

 * runner.setParams(params);                // Set new parameters
 * content = runner.run();
 * if (runner.statusCode() != 0)
 * {
 *      qDebug() << "ERROR:" << content;
 * }
 * qDebug() << content;
 * \endcode
 */
class PandocRunner : public QProcess
{
    Q_OBJECT

public:
    PandocRunner(const QStringList &params, QObject* parent = 0);
    QString content();
    QString run();
    int statusCode() const;
    void setParams(const QStringList &params);


private slots:
    void finishedProcess(int exitCode);
    void readyReadOutput();
    void readyReadError();

private:
    QStringList mParams;
    QString mContent;
    int mStatusCode;
};

#endif // PANDOCRUNNER_H
