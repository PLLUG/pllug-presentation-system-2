#include "documentimportstrategy.h"
#include "abstractpresentationelementfactory.h"

DocumentImportStrategy::DocumentImportStrategy()
{
}

std::shared_ptr<PresentationElementFactory> DocumentImportStrategy::presentationElementFactory() const
{
    return mPresentationElementFactory;
}
