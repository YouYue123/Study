from langchain_core.documents import Document
from langchain_core.runnables import chain

try:
    from vectordb.chroma import ChromaVectorStore
    vector_store = ChromaVectorStore()
except ImportError:
    vector_store = None  # or raise a more descriptive error

@chain
def retriever(query: str) -> list[Document]:
    if vector_store is None:
        raise ImportError("Could not import 'vector_store' from 'vectordb.chroma'")
    return vector_store.query(query)