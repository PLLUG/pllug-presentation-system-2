#include <QString>
#include <QtTest>

class ImportDivisionTest : public QObject
{
    Q_OBJECT

public:
    ImportDivisionTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
};

ImportDivisionTest::ImportDivisionTest()
{
}

void ImportDivisionTest::initTestCase()
{
}

void ImportDivisionTest::cleanupTestCase()
{
}

void ImportDivisionTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(ImportDivisionTest)

#include "tst_importdivisiontest.moc"
