#include <QString>
#include <QtTest>

#include "pandocrunner.h"

class PandocTest : public QObject
{
    Q_OBJECT

public:
    PandocTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();

    void test_initContent();
    void test_initError();
    void test_initStatus();
    void test_buildParams();
};

PandocTest::PandocTest()
{
}

void PandocTest::initTestCase()
{
}

void PandocTest::cleanupTestCase()
{
}

void PandocTest::test_initContent()
{
    PandocRunner runner;
    QCOMPARE(runner.content(), QString(""));
}

void PandocTest::test_initError()
{
    PandocRunner runner;
    QCOMPARE(runner.error(), QString(""));
}

void PandocTest::test_initStatus()
{
    PandocRunner runner;
    QCOMPARE(runner.statusCode(), 0);
}

void PandocTest::test_buildParams()
{
    PandocRunner runner;
    QStringList manualParams;
    manualParams << "input.md";
    manualParams << "-f" << "markdown";
    manualParams << "-t" << "html";

    QStringList calculatedParams = runner.buildParams(
                PandocRunner::Markdown,
                PandocRunner::HTML,
                "input.md");

    QCOMPARE(calculatedParams.join(" "), manualParams.join(" "));
}

QTEST_APPLESS_MAIN(PandocTest)

#include "tst_pandoctest.moc"
