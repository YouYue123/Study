import logging
import os
import hashlib
import chromadb
from langchain_openai import OpenAIEmbeddings
from langchain_chroma import Chroma
from pydantic import SecretStr
from langchain_core.documents import Document


class ChromaVectorStore:
    """A class to manage Chroma vector store operations"""

    def __init__(
        self,
        collection_name: str = "yy_docs",
    ):
        """Initialize the Chroma vector store"""
        self.collection_name = collection_name

        self.embeddings = OpenAIEmbeddings(
            api_key=SecretStr(os.getenv("OPENAI_API_KEY") or ""),
            model="text-embedding-3-large",
        )
        self.vector_store = Chroma(
            collection_name=self.collection_name,
            embedding_function=self.embeddings,
            client=chromadb.HttpClient(
                ssl=True,
                host="api.trychroma.com",
                tenant=os.getenv("CHROMA_TENANT") or "",
                database=os.getenv("CHROMA_DATABASE") or "",
                headers={
                    "x-chroma-token": os.getenv("CHROMA_TOKEN") or "",
                },
            ),
        )

    def _generate_document_id(self, document: Document) -> str:
        """Generate a SHA-256 hash of the document content as ID"""
        # Combine page_content and metadata for a more unique hash
        content = document.page_content
        metadata_str = str(sorted(document.metadata.items())) if document.metadata else ""
        combined_content = f"{content}{metadata_str}"
        
        # Generate SHA-256 hash
        hash_object = hashlib.sha256(combined_content.encode('utf-8'))
        return f"doc_{hash_object.hexdigest()[:16]}"  # Use first 16 characters for readability

    def upsert_documents(self, documents: list[Document]):
        if not documents:
            logging.warning("No documents provided for upsert")
            return

        # Generate IDs based on document content
        ids = [self._generate_document_id(doc) for doc in documents]
        assert len(ids) == len(documents), "Number of IDs must match number of documents"
        try:
            # Upsert documents into the vector store
            self.vector_store.add_documents(documents=documents, ids=ids)
            logging.info(f"Successfully upserted {len(documents)} documents")
        except Exception as e:
            logging.error(f"Error upserting documents: {e}")
            raise
        return ids

    def query(self, queryStr: str, k: int = 5):
        """Query documents with similarity scores"""
        return self.vector_store.similarity_search_with_score(queryStr, k=k)
    
    def query_simple(self, queryStr: str):
        """Simple query without scores (for backward compatibility)"""
        return self.vector_store.similarity_search(queryStr)
