#include <QString>
#include <QtTest>

#include "slide.h"

#include "testelement.h"

#include <memory>

class SlideTest : public QObject
{
    Q_OBJECT

public:
    SlideTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void test_elementAdded_elementInList();
};

SlideTest::SlideTest()
{
}

void SlideTest::initTestCase()
{
}

void SlideTest::cleanupTestCase()
{
}

void SlideTest::test_elementAdded_elementInList()
{
    Slide slide;

    QCOMPARE(slide.elementsCount(), 0);

    auto testElement1 = std::make_unique<TestElement>();
    slide.addElement(std::move(testElement1));
    QCOMPARE(slide.elementsCount(), 1);

    auto testElement2 = std::make_unique<TestElement>();
    slide.addElement(std::move(testElement2));
    QCOMPARE(slide.elementsCount(), 2);
}

QTEST_APPLESS_MAIN(SlideTest)

#include "tst_slidetest.moc"
