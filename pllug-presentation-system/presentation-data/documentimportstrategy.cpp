#include "documentimportstrategy.h"
#include "presentationelementfactory.h"

DocumentImportStrategy::DocumentImportStrategy()
{
}

std::shared_ptr<PresentationElementFactory> DocumentImportStrategy::presentationElementFactory() const
{
    return mPresentationElementFactory;
}
