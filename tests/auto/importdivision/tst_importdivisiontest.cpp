#include <QString>
#include <QtTest>
#include <QFile>
#include <QList>
#include <memory>

#include "domdocumentdivider.h"
#include "htmlimport.h"
#include "header.h"
#include "separator.h"
#include "paragraph.h"
#include "presentationelement.h"
#include "presentationelementfactory.h"
#include "presentation.h"
#include "testutility.h"

class ImportDivisionTest : public QObject
{
    Q_OBJECT

public:
    ImportDivisionTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void test_OneParagraph_SlideWithParagraph();
    void test_TwoHeaders_TwoSlides();
    void test_SeparatedParagraphs_TwoSlides();
    void test_SeparatorsHeadersParagraphs_ThreeSlides();
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

void ImportDivisionTest::test_OneParagraph_SlideWithParagraph()
{
    QFile htmlFile(TestUtility::getResourcePath("single_paragraph_root.html"));
    htmlFile.open(QFile::ReadOnly);
    QByteArray input = htmlFile.readAll();
    htmlFile.close();
    std::shared_ptr<PresentationElementFactory> factoryPtr(new PresentationElementFactory());
    HtmlImport importObject(factoryPtr);
    QList<PresentationElement *> elements = importObject.import(input);
    DomDocumentDivider divider;
    std::unique_ptr<Presentation> presentation = divider.import(elements);

    QVERIFY(presentation != nullptr);
    QCOMPARE(presentation->slideCount(), 1);
    QCOMPARE(presentation->slide(0)->elementsCount(), 1);
    QVERIFY(dynamic_cast<Paragraph *>(presentation->slide(0)->element(0)) != nullptr);
}

void ImportDivisionTest::test_TwoHeaders_TwoSlides()
{
    QFile htmlFile(TestUtility::getResourcePath("two_headers.html"));
    htmlFile.open(QFile::ReadOnly);
    QByteArray input = htmlFile.readAll();
    htmlFile.close();
    std::shared_ptr<PresentationElementFactory> factoryPtr(new PresentationElementFactory());
    HtmlImport importObject(factoryPtr);
    QList<PresentationElement *> elements = importObject.import(input);
    DomDocumentDivider divider;
    std::unique_ptr<Presentation> presentation = divider.import(elements);

    QVERIFY(presentation != nullptr);
    QCOMPARE(presentation->slideCount(), 2);
    QCOMPARE(presentation->slide(0)->elementsCount(), 2);
    QVERIFY(dynamic_cast<Header *>(presentation->slide(0)->element(0)) != nullptr);
    QVERIFY(dynamic_cast<Paragraph *>(presentation->slide(0)->element(1)) != nullptr);
    QCOMPARE(presentation->slide(1)->elementsCount(), 2);
    QVERIFY(dynamic_cast<Header *>(presentation->slide(1)->element(0)) != nullptr);
    QVERIFY(dynamic_cast<Paragraph *>(presentation->slide(1)->element(1)) != nullptr);
}

void ImportDivisionTest::test_SeparatedParagraphs_TwoSlides()
{
    QFile htmlFile(TestUtility::getResourcePath("separated_paragraphs.html"));
    htmlFile.open(QFile::ReadOnly);
    QByteArray input = htmlFile.readAll();
    htmlFile.close();
    std::shared_ptr<PresentationElementFactory> factoryPtr(new PresentationElementFactory());
    HtmlImport importObject(factoryPtr);
    QList<PresentationElement *> elements = importObject.import(input);
    DomDocumentDivider divider;
    std::unique_ptr<Presentation> presentation = divider.import(elements);

    QVERIFY(presentation != nullptr);
    QCOMPARE(presentation->slideCount(), 2);
    QCOMPARE(presentation->slide(0)->elementsCount(), 1);
    QVERIFY(dynamic_cast<Paragraph *>(presentation->slide(0)->element(0)) != nullptr);
    QCOMPARE(presentation->slide(1)->elementsCount(), 1);
    QVERIFY(dynamic_cast<Paragraph *>(presentation->slide(1)->element(0)) != nullptr);
}

void ImportDivisionTest::test_SeparatorsHeadersParagraphs_ThreeSlides()
{
    QFile htmlFile(TestUtility::getResourcePath("separator_headers.html"));
    htmlFile.open(QFile::ReadOnly);
    QByteArray input = htmlFile.readAll();
    htmlFile.close();
    std::shared_ptr<PresentationElementFactory> factoryPtr(new PresentationElementFactory());
    HtmlImport importObject(factoryPtr);
    QList<PresentationElement *> elements = importObject.import(input);
    DomDocumentDivider divider;
    std::unique_ptr<Presentation> presentation = divider.import(elements);

    QVERIFY(presentation != nullptr);
    QCOMPARE(presentation->slideCount(), 3);
    QCOMPARE(presentation->slide(0)->elementsCount(), 2);
    QVERIFY(dynamic_cast<Header *>(presentation->slide(0)->element(0)) != nullptr);
    QVERIFY(dynamic_cast<Paragraph *>(presentation->slide(0)->element(1)) != nullptr);
    QCOMPARE(presentation->slide(1)->elementsCount(), 1);
    QVERIFY(dynamic_cast<Paragraph *>(presentation->slide(1)->element(0)) != nullptr);
    QCOMPARE(presentation->slide(2)->elementsCount(), 2);
    QVERIFY(dynamic_cast<Header *>(presentation->slide(2)->element(0)) != nullptr);
    QVERIFY(dynamic_cast<Paragraph *>(presentation->slide(2)->element(1)) != nullptr);
}

QTEST_APPLESS_MAIN(ImportDivisionTest)

#include "tst_importdivisiontest.moc"
