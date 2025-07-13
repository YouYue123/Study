from env import set_env
set_env()

import logging
import os
import glob

from langchain_community.document_loaders import PyPDFLoader
from langchain_text_splitters import RecursiveCharacterTextSplitter

from ..chroma import ChromaVectorStore

def initialize_vector_store():
    """Initialize vector store with documents - run this once"""
    logging.info("Initializing vector store")
    vector_store = ChromaVectorStore()
    
    # Find all PDF files in the docs folder
    docs_folder = "./docs"
    pdf_pattern = os.path.join(docs_folder, "*.pdf")
    pdf_files = glob.glob(pdf_pattern)
    
    if not pdf_files:
        logging.warning(f"No PDF files found in {docs_folder}")
        return vector_store
    
    logging.info(f"Found {len(pdf_files)} PDF files: {pdf_files}")
    text_splitter = RecursiveCharacterTextSplitter(chunk_size=1000, chunk_overlap=200)

    for pdf_path in pdf_files:
        logging.info(f"Loading PDF: {pdf_path}")
        try:
            loader = PyPDFLoader(pdf_path)
            pdf_docs = loader.load()
            splitted_docs = text_splitter.split_documents(pdf_docs)
            ids = vector_store.upsert_documents(documents=splitted_docs)
            if ids is not None:
                logging.info(f"Upserted {len(ids)} documents to vector store")
            
        except Exception as e:
            logging.error(f"Error loading {pdf_path}: {e}")
            continue
    
    return vector_store

if __name__ == "__main__":
    logging.basicConfig(level=logging.INFO)
    initialize_vector_store()