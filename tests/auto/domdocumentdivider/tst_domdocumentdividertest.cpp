#include <QString>
#include <QtTest>

#include "domdocumentdivider.h"
#include "presentation.h"
#include "presentationelementfactory.h"
#include "paragraph.h"
#include "presentation.h"
#include "separator.h"
#include "testutility.h"

#include <QFile>
#include <memory>
#include <QList>
#include <QDebug>

class DomDocumentDividerTest : public QObject
{
    Q_OBJECT

public:
    DomDocumentDividerTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void test_importOneParagraph_slideWithOneParagraph();
    void test_importTwoParagraphs_slideWithTwoParagraphs();
    void test_importSeparatedParagraphs_twoSlides();
};

DomDocumentDividerTest::DomDocumentDividerTest()
{
}

void DomDocumentDividerTest::initTestCase()
{
}

void DomDocumentDividerTest::cleanupTestCase()
{
}

void DomDocumentDividerTest::test_importOneParagraph_slideWithOneParagraph()
{   
    QString path = TestUtility::getResourcePath("single_paragraph.html");
    QFile htmlFile(path);
    htmlFile.open(QFile::ReadOnly);
    QByteArray htmlByteArray = htmlFile.readAll();
    htmlFile.close();
    Paragraph *paragraph = new Paragraph (htmlByteArray);
    QList<PresentationElement *> elementsList;
    elementsList.append(paragraph);

    DomDocumentDivider divider;
    std::unique_ptr<Presentation> presentation = divider.import(elementsList);

    QVERIFY(presentation != nullptr);
    QCOMPARE(presentation->slideCount(), 1);
    QCOMPARE(presentation->slide(0)->elementsCount(), 1);
    QVERIFY(dynamic_cast<Paragraph *>(presentation->slide(0)->element(0)) != nullptr);
    QCOMPARE(presentation->slide(0)->element(0)->toHtml(), static_cast<QString>(htmlByteArray));
}

void DomDocumentDividerTest::test_importTwoParagraphs_slideWithTwoParagraphs()
{
    QString path = TestUtility::getResourcePath("single_paragraph.html");
    QFile htmlFile(path);
    htmlFile.open(QFile::ReadOnly);
    QByteArray htmlByteArray = htmlFile.readAll();
    htmlFile.close();
    Paragraph *paragraph1 = new Paragraph (htmlByteArray);
    Paragraph *paragraph2 = new Paragraph (htmlByteArray);
    QList<PresentationElement *> elementsList;
    elementsList.append(paragraph1);
    elementsList.append(paragraph2);

    DomDocumentDivider divider;
    std::unique_ptr<Presentation> presentation = divider.import(elementsList);

    QVERIFY(presentation != nullptr);
    QCOMPARE(presentation->slideCount(), 1);
    QCOMPARE(presentation->slide(0)->elementsCount(), 2);
    QVERIFY(dynamic_cast<Paragraph *>(presentation->slide(0)->element(0)) != nullptr);
    QCOMPARE(presentation->slide(0)->element(0)->toHtml(), static_cast<QString>(htmlByteArray));
    QVERIFY(dynamic_cast<Paragraph *>(presentation->slide(0)->element(1)) != nullptr);
    QCOMPARE(presentation->slide(0)->element(1)->toHtml(), static_cast<QString>(htmlByteArray));
}

void DomDocumentDividerTest::test_importSeparatedParagraphs_twoSlides()
{
    QString path = TestUtility::getResourcePath("single_paragraph.html");
    QFile htmlFile(path);
    htmlFile.open(QFile::ReadOnly);
    QByteArray htmlByteArray = htmlFile.readAll();
    htmlFile.close();
    Paragraph *paragraph1 = new Paragraph (htmlByteArray);
    Separator *separator = new Separator("<hr />");
    Paragraph *paragraph2 = new Paragraph (htmlByteArray);
    QList<PresentationElement *> elementsList;
    elementsList.append(paragraph1);
    elementsList.append(separator);
    elementsList.append(paragraph2);

    DomDocumentDivider divider;
    std::unique_ptr<Presentation> presentation = divider.import(elementsList);

    QVERIFY(presentation != nullptr);
    QCOMPARE(presentation->slideCount(), 2);
    QCOMPARE(presentation->slide(0)->elementsCount(), 1);
    QCOMPARE(presentation->slide(1)->elementsCount(), 1);
    QVERIFY(dynamic_cast<Paragraph *>(presentation->slide(0)->element(0)) != nullptr);
    QCOMPARE(presentation->slide(0)->element(0)->toHtml(), static_cast<QString>(htmlByteArray));
    QVERIFY(dynamic_cast<Paragraph *>(presentation->slide(1)->element(0)) != nullptr);
    QCOMPARE(presentation->slide(1)->element(0)->toHtml(), static_cast<QString>(htmlByteArray));
}

QTEST_APPLESS_MAIN(DomDocumentDividerTest)

#include "tst_domdocumentdividertest.moc"
