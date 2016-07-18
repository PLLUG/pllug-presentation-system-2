#include <QString>
#include <QtTest>

#include "domdocumentdivider.h"
#include "presentation.h"
#include "concretepresentationelementfactory.h"
#include "paragraph.h"
#include "presentation.h"

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
    QFile htmlFile("D:/Qt_projects/SUMMERCAMP2016/pllug-presentation-system-2/tests/auto/domdocumentdivider/test-data/single_paragraph.html");
    htmlFile.open(QFile::ReadOnly);
    QByteArray htmlByteArray = htmlFile.readAll();
    Paragraph *paragraph = new Paragraph (htmlByteArray);
    QList<PresentationElement *> elementsList;
    elementsList.append(paragraph);

    DomDocumentDivider divider;
    std::unique_ptr<Presentation> presentation = divider.import(elementsList);

    QVERIFY(presentation != nullptr);
    QCOMPARE(presentation->slideCount(), 1);
    QCOMPARE(presentation->getSlide(0)->elementsCount(), 1);
    QVERIFY(dynamic_cast<Paragraph *>(presentation->getSlide(0)->getElement(0)) != nullptr);
    QCOMPARE(presentation->getSlide(0)->getElement(0)->toHtml(), static_cast<QString>(htmlByteArray));

    htmlFile.close();
}

QTEST_APPLESS_MAIN(DomDocumentDividerTest)

#include "tst_domdocumentdividertest.moc"
