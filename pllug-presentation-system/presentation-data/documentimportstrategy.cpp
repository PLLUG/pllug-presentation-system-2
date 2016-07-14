#include "documentimportstrategy.h"

DocumentImportStrategy::DocumentImportStrategy(std::shared_ptr<PresentationElementFactory> presentationElementFactory)
    : mPresentationElementFactory {presentationElementFactory}
{
}

std::shared_ptr<PresentationElementFactory> DocumentImportStrategy::presentationElementFactory() const
{
    return mPresentationElementFactory;
}
