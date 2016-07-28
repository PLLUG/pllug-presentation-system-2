#include <QString>
#include <QtTest>
#include <memory>
#include <QDebug>
#include <QFile>
#include <QModelIndex>
#include "presentationmodel.h"
#include "modeltest.h"
#include "presentation.h"
#include "presentationelement.h"
#include "domdocumentdivider.h"
#include "presentationelementfactory.h"
#include "htmlimport.h"
#include "slide.h"
#include "testutility.h"

#include "slideproxymodel.h"

class PresentationModelTest : public QObject
{
    Q_OBJECT

public:
    PresentationModelTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void test_oneSlide_ModelWithOneRow();
    void test_2();
};

PresentationModelTest::PresentationModelTest()
{
}

void PresentationModelTest::initTestCase()
{
}

void PresentationModelTest::cleanupTestCase()
{
}

void PresentationModelTest::test_oneSlide_ModelWithOneRow()
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

    PresentationModel *model = new PresentationModel();
    model->setPresentation(presentation.release());

    for(int i = 0; i < model->rowCount(model->index(0,0).parent()); ++i)
    {
        QModelIndex slideIndex = model->index(i,0);
        for(int j = 0; j < model->rowCount(slideIndex); ++j)
        {
            QModelIndex elementIndex = model->index(j,0,slideIndex);
            PresentationElement *element = static_cast<PresentationElement *>(elementIndex.internalPointer());
            qDebug() << "Slide" << i << "Element" << j << element->toHtml();
        }
    }
}

void PresentationModelTest::test_2()
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

    PresentationModel *model = new PresentationModel();
    Presentation *pres = presentation.release();
    model->setPresentation(pres);
    SlideProxyModel slideModel;
    slideModel.setSourceModel(model);

    for(int i = 0; i < pres->slideCount(); ++i)
    {
        slideModel.setSlideNumber(i);
        for(int j = 0; j < slideModel.rowCount(); ++j)
        {
            QModelIndex elementIndex = slideModel.index(j,0);
            PresentationElement *element = static_cast<PresentationElement *>(elementIndex.internalPointer());
            qDebug() << "Slide" << i << "Element" << j << element->toHtml();
        }
    }
}

QTEST_APPLESS_MAIN(PresentationModelTest)

#include "tst_presentationmodeltest.moc"
