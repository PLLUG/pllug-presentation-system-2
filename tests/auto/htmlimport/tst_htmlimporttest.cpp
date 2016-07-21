#include <QString>
#include <QtTest>
#include <QFile>
#include <QList>
#include <memory>
#include <QDebug>
#include <QDir>

#include "htmlimport.h"
#include "presentationelement.h"
#include "concretepresentationelementfactory.h"
#include "paragraph.h"
#include "separator.h"
#include "header.h"

class HtmlImportTest : public QObject
{
    Q_OBJECT

public:
    HtmlImportTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void test_importOneParagraph_OneParagraph();
    void test_importTwoParagraphs_TwoParagraphs();
    void test_importSeparatedParagraphs_ParagraphSeparatorParagraph();
    void test_importHtmlWithHeader_HeaderParagraphSeparator();
};

HtmlImportTest::HtmlImportTest()
{
}

void HtmlImportTest::initTestCase()
{
}

void HtmlImportTest::cleanupTestCase()
{
}

void HtmlImportTest::test_importOneParagraph_OneParagraph()
{
    QString path = QString("%1/%2").arg(QDir().currentPath()).arg("htmlimport/test-data/single_paragraph.html");
    QFile htmlFile(path);
    htmlFile.open(QFile::ReadOnly);
    QByteArray input = htmlFile.readAll();
    std::shared_ptr<PresentationElementFactory> factoryPtr(new ConcretePresentationElementFactory());
    HtmlImport importObject(factoryPtr);
    QList<PresentationElement *> elements = importObject.import(input);

    QCOMPARE(elements.count(), 1);
    QVERIFY(dynamic_cast<Paragraph *>(elements[0]) != nullptr);
}

void HtmlImportTest::test_importTwoParagraphs_TwoParagraphs()
{
    QString path = QString("%1/%2").arg(QDir().currentPath()).arg("htmlimport/test-data/two_paragraphs.html");
    QFile htmlFile(path);
    htmlFile.open(QFile::ReadOnly);
    QByteArray input = htmlFile.readAll();
    std::shared_ptr<PresentationElementFactory> factoryPtr(new ConcretePresentationElementFactory());
    HtmlImport importObject(factoryPtr);
    QList<PresentationElement *> elements = importObject.import(input);

    QCOMPARE(elements.count(), 2);
    QVERIFY(dynamic_cast<Paragraph *>(elements[0]) != nullptr);
    QVERIFY(dynamic_cast<Paragraph *>(elements[1]) != nullptr);
}

void HtmlImportTest::test_importSeparatedParagraphs_ParagraphSeparatorParagraph()
{
    QString path = QString("%1/%2").arg(QDir().currentPath()).arg("htmlimport/test-data/separated_paragraphs.html");
    QFile htmlFile(path);
    htmlFile.open(QFile::ReadOnly);
    QByteArray input = htmlFile.readAll();
    std::shared_ptr<PresentationElementFactory> factoryPtr(new ConcretePresentationElementFactory());
    HtmlImport importObject(factoryPtr);
    QList<PresentationElement *> elements = importObject.import(input);

    QCOMPARE(elements.count(), 3);
    QVERIFY(dynamic_cast<Paragraph *>(elements[0]) != nullptr);
    QVERIFY(dynamic_cast<Separator *>(elements[1]) != nullptr);
    QVERIFY(dynamic_cast<Paragraph *>(elements[2]) != nullptr);
}

void HtmlImportTest::test_importHtmlWithHeader_HeaderParagraphSeparator()
{
    QString path = QString("%1/%2").arg(QDir().currentPath()).arg("htmlimport/test-data/header.html");
    QFile htmlFile(path);
    htmlFile.open(QFile::ReadOnly);
    QByteArray input = htmlFile.readAll();
    std::shared_ptr<PresentationElementFactory> factoryPtr(new ConcretePresentationElementFactory());
    HtmlImport importObject(factoryPtr);
    QList<PresentationElement *> elements = importObject.import(input);

    QCOMPARE(elements.count(), 5);
    QVERIFY(dynamic_cast<Header *>(elements[0]) != nullptr);
    QVERIFY(dynamic_cast<Paragraph *>(elements[1]) != nullptr);
    QVERIFY(dynamic_cast<Separator *>(elements[2]) != nullptr);
    QVERIFY(dynamic_cast<Header *>(elements[3]) != nullptr);
    QVERIFY(dynamic_cast<Paragraph *>(elements[4]) != nullptr);
}

QTEST_APPLESS_MAIN(HtmlImportTest)

#include "tst_htmlimporttest.moc"
