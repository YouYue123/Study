import logging
import os
from dotenv import load_dotenv

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def set_env():
    load_dotenv(override=True)
    logging.info("Loaded .env file")
    logging.info(f"LANGSMITH_TRACING: {os.getenv('LANGSMITH_TRACING')}")
    logging.info(f"LANGSMITH_PROJECT: {os.getenv('LANGSMITH_PROJECT')}")
    logging.info(f"LANGSMITH_API_KEY: {os.getenv('LANGSMITH_API_KEY')}")
    logging.info(f"OPENAI_API_KEY: {os.getenv('OPENAI_API_KEY')}")
    logging.info(f"OPEN_ROUTER_API_KEY: {os.getenv('OPEN_ROUTER_API_KEY')}")
    logging.info(f"CHROMA_TENANT: {os.getenv('CHROMA_TENANT')}")
    logging.info(f"CHROMA_DATABASE: {os.getenv('CHROMA_DATABASE')}")
    logging.info(f"CHROMA_TOKEN: {os.getenv('CHROMA_TOKEN')}")