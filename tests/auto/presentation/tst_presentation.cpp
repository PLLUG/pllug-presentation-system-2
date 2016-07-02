#include <QtTest>

// add necessary includes here

class Presentation : public QObject
{
    Q_OBJECT

public:
    Presentation();
    ~Presentation();

private slots:
    void test_case1();

};

Presentation::Presentation()
{

}

Presentation::~Presentation()
{

}

void Presentation::test_case1()
{

}

QTEST_APPLESS_MAIN(Presentation)

#include "tst_presentation.moc"
