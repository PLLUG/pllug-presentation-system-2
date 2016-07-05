#include <QtTest>

#include <memory>
#include <utility>

#include "presentation.h"
#include "slide.h"
// add necessary includes here

class PresentationTest : public QObject
{
    Q_OBJECT

public:
    PresentationTest();
    ~PresentationTest();

private slots:
    void test_appendSlide_slideInList();
    void test_copyConstruction_slidesInList();
    void test_copyAssigment_slidesInList();
};

PresentationTest::PresentationTest()
{

}

PresentationTest::~PresentationTest()
{

}

void PresentationTest::test_appendSlide_slideInList()
{
    Presentation presentation;

    QCOMPARE(presentation.slideCount(), 0);

    auto slide1 = std::make_unique<Slide>();
    presentation.appendSlide(std::move(slide1));
    QCOMPARE(presentation.slideCount(), 1);

    auto slide2 = std::make_unique<Slide>();
    presentation.appendSlide(std::move(slide2));
    QCOMPARE(presentation.slideCount(), 2);
}

void PresentationTest::test_copyConstruction_slidesInList()
{
    Presentation presentation;

    auto slide1 = std::make_unique<Slide>();
    presentation.appendSlide(std::move(slide1));

    auto slide2 = std::make_unique<Slide>();
    presentation.appendSlide(std::move(slide2));

    Presentation presentationCopy(presentation);
    QCOMPARE(presentationCopy.slideCount(), 2);
}

void PresentationTest::test_copyAssigment_slidesInList()
{
    Presentation presentation;

    auto slide1 = std::make_unique<Slide>();
    presentation.appendSlide(std::move(slide1));

    auto slide2 = std::make_unique<Slide>();
    presentation.appendSlide(std::move(slide2));

    Presentation presentationCopy;
    presentationCopy = presentation;
    QCOMPARE(presentationCopy.slideCount(), 2);
}

QTEST_APPLESS_MAIN(PresentationTest)

#include "tst_presentation.moc"
