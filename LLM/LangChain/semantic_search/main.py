import os
from langchain_core.documents import Document
from langchain_community.document_loaders import PyPDFLoader
import logging
from langchain_text_splitters import RecursiveCharacterTextSplitter
from langchain_openai import OpenAIEmbeddings
from dotenv import load_dotenv
from pydantic import SecretStr
from langchain_community.vectorstores import InMemoryVectorStore

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

load_dotenv()
logging.info("Loaded .env file")
logging.info(f"LANGSMITH_TRACING: {os.getenv('LANGSMITH_TRACING')}")
logging.info(f"LANGSMITH_PROJECT: {os.getenv('LANGSMITH_PROJECT')}")
logging.info(f"LANGSMITH_API_KEY: {os.getenv('LANGSMITH_API_KEY')}")
logging.info(f"OPENAI_API_KEY: {os.getenv('OPENAI_API_KEY')}")

documents = [
    Document(
        page_content="Dogs are great companions, known for their loyalty and friendliness.",
        metadata={"source": "mammal-pets-doc"},
    ),
    Document(
        page_content="Cats are independent pets that often enjoy their own space.",
        metadata={"source": "mammal-pets-doc"},
    ),
]

logging.info("Loading pdf")
sample_pdf_path = "sample.pdf"
loader = PyPDFLoader(sample_pdf_path)
docs = loader.load()
logging.info(docs[0].metadata)

text_splitter = RecursiveCharacterTextSplitter(
    chunk_size=1000, chunk_overlap=200, add_start_index=True
)

all_splits = text_splitter.split_documents(docs)

logging.info(f"Split {len(all_splits)} chunks")


embeddings = OpenAIEmbeddings(
    api_key=SecretStr(os.getenv("OPENAI_API_KEY") or ""),
    model="text-embedding-3-large",
)

vector_1 = embeddings.embed_documents(texts=[all_splits[0].page_content])
vector_2 = embeddings.embed_documents(texts=[all_splits[1].page_content])
assert len(vector_1) == len(vector_2)

logging.info(f"Vector 1: {vector_1[:10]}")
logging.info(f"Vector 2: {vector_2[:10]}")

# vector_store = InMemoryVectorStore(embeddings)

# ids = vector_store.add_documents(documents=all_splits)