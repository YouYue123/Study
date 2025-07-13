from langchain_core.documents import Document
from langchain_core.runnables import chain
import logging
from typing import List, Dict, Any

try:
    from vectordb.chroma import ChromaVectorStore
    vector_store = ChromaVectorStore()
except ImportError:
    vector_store = None  # or raise a more descriptive error

logger = logging.getLogger(__name__)


@chain
def retriever(query: str):
    if vector_store is None:
        raise ImportError("Could not import 'vector_store' from 'vectordb.chroma'")
    # Get documents with similarity scores
    docs_with_scores = vector_store.query(query)
    logger.info(f"Retrieved {len(docs_with_scores)} documents for query: {query}")
    return docs_with_scores

# Create the RAG chain with enhanced context
@chain
def prepare_context(retrieval_result: dict[str, Any]) -> dict[str, Any]:
    logging.info("preparing context..sdfsdfs.")
    logging.info(f"retrieval_result: {retrieval_result}")
    context = format_context_for_rag(retrieval_result)
    stats = retrieval_result.get("retrieval_stats", {})
    documents = retrieval_result.get("documents", [])
    logging.info("prepared context ✅")

    return {
        "context": context,
        "num_docs": stats.get("total_documents_retrieved", 0),
        "avg_score": stats.get("average_similarity_score", 0),
        "sources": ", ".join(
            set(doc.metadata.get("source", "unknown") for doc in documents),
        ),
    }


def format_context_for_rag(retrieval_result: Dict[str, Any]) -> str:
    """
    Format the retrieval result into a structured context string for RAG.

    Args:
        retrieval_result: The result from the enhanced retriever

    Returns:
        Formatted context string
    """
    if not retrieval_result["documents"]:
        return "No relevant documents found."

    context_parts = []

    # Add retrieval statistics
    stats = retrieval_result["retrieval_stats"]
    if stats.get("retrieval_successful"):
        context_parts.append(
            f"Retrieved {stats['total_documents_retrieved']} relevant documents "
            f"(avg similarity: {stats['average_similarity_score']:.3f})"
        )

    # Add documents with metadata
    for i, doc in enumerate(retrieval_result["documents"]):
        doc_meta = doc.metadata
        content = doc.page_content.strip()

        # Create document header with metadata
        header = f"[Document {i+1}]"
        if "source" in doc_meta:
            header += f" Source: {doc_meta['source']}"
        if "similarity_score" in doc_meta:
            header += f" (Relevance: {doc_meta['similarity_score']:.3f})"
        if "date" in doc_meta:
            header += f" Date: {doc_meta['date']}"

        context_parts.append(f"{header}\n{content}\n")

    return "\n".join(context_parts)


# Convenience function for backward compatibility
@chain
def simple_retriever(query: str) -> List[Document]:
    """Simple retriever that returns just the documents (for backward compatibility)"""
    result = retriever.invoke(query)
    return result["documents"]
