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
    
    all_splits = []
    text_splitter = RecursiveCharacterTextSplitter(
        chunk_size=1000, chunk_overlap=200, add_start_index=True
    )
    
    # Load and split all PDF files
    for pdf_path in pdf_files:
        logging.info(f"Loading PDF: {pdf_path}")
        try:
            loader = PyPDFLoader(pdf_path)
            docs = loader.load()
            splits = text_splitter.split_documents(docs)
            all_splits.extend(splits)
            logging.info(f"Split {len(splits)} chunks from {pdf_path}")
        except Exception as e:
            logging.error(f"Error loading {pdf_path}: {e}")
            continue
    
    if not all_splits:
        logging.warning("No documents were successfully loaded and split")
        return vector_store
    
    logging.info(f"Total chunks to upsert: {len(all_splits)}")
    
    # Use upsert to handle potential duplicates
    ids = vector_store.upsert_documents(documents=all_splits)
    if ids is not None:
        logging.info(f"Upserted {len(ids)} documents to vector store")
    
    return vector_store

if __name__ == "__main__":
    logging.basicConfig(level=logging.INFO)
    initialize_vector_store()