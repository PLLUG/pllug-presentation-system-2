#include <QString>
#include <QtTest>

#include "domdocumentdivider.h"
#include "presentation.h"
#include "concretepresentationelementfactory.h"

#include <QFile>
#include <memory>

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
    QFile htmlFile("/domdocumentdivider/test-data/one_paragraph.html");
    htmlFile.open(QFile::ReadOnly);
    QByteArray htmlByteArray = htmlFile.readAll();

    ConcretePresentationElementFactory *factoryPtr = new ConcretePresentationElementFactory();
    DomDocumentDivider divider(std::make_shared<ConcretePresentationElementFactory>(*factoryPtr));

    std::unique_ptr<Presentation> presentation = divider.import(htmlByteArray);

    QCOMPARE(presentation->slideCount(), 1);

//    // Check if the first slide contains 1 element.
//    QCOMPARE(presentation->slide(1)->elementCount(), 1);

//    // Check if element's type is text.
//    QCOMPARE(presentation->slide(1)->element(1)->type(), PresentationElement::ElementType::Paragraph);

    htmlFile.close();
}

QTEST_APPLESS_MAIN(DomDocumentDividerTest)

#include "tst_domdocumentdividertest.moc"
