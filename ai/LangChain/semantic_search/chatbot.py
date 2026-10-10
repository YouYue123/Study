from langchain_core.callbacks import BaseCallbackHandler
from langchain_core.runnables import RunnableLambda, RunnablePassthrough
from pydantic import SecretStr
import streamlit as st
import logging
import os

from langchain_openai import ChatOpenAI
from langchain_core.prompts import ChatPromptTemplate
from langchain_core.output_parsers import StrOutputParser

from env import set_env
from retriever import prepare_context, retriever

# Set up environment
set_env()

# Configure logging
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

class PromptLoggingCallback(BaseCallbackHandler):
    def on_llm_start(self, serialized, prompts, **kwargs):
        """Log prompts when LLM starts"""
        logger.info("=== PROMPT BEING SENT TO LLM ===")
        for i, prompt in enumerate(prompts):
            logger.info(f"Prompt {i+1}: {prompt}")
        logger.info("=== END PROMPT ===")

class ChatbotApp:
    def __init__(self):
        self.llm = ChatOpenAI(
            api_key=SecretStr(os.getenv("OPENROUTER_API_KEY") or ""),
            base_url=os.getenv("OPENROUTER_BASE_URL"),
            model="gpt-4o-mini",
            callbacks=[PromptLoggingCallback()]
        )

        # Create the RAG chain
        self.rag_chain = self._create_rag_chain()

    def _create_rag_chain(self):
        """Create a RAG chain that combines retrieval and generation"""

        # Enhanced template for the RAG prompt
        template = """You are a personal document assistant AI that helps users find and understand information from their personal document collection. 
        Your role is to search through the provided context (which contains the user's personal documents) and answer questions about their content.
        
        Use the following pieces of context to answer the question at the end.
        If you don't know the answer based on the provided context, just say that you don't know, don't try to make up an answer.
        
        
        Context (from your personal documents):
        {context}
        
        Question: {question}
        
        Answer:"""

        prompt = ChatPromptTemplate.from_template(template)
        
  

        # Fixed RAG chain structure
        rag_chain = (
            {
                "question": RunnablePassthrough(),
                "context": retriever
            }
            | prompt
            | self.llm
            | StrOutputParser()
        )

        return rag_chain

    def get_response(self, user_question: str) -> str:
        """Get response from the RAG chain"""
        try:
            response = self.rag_chain.invoke(user_question)
            return response
        except Exception as e:
            logger.error(f"Error getting response: {e}")
            return f"Sorry, I encountered an error: {str(e)}"


def main():
    st.set_page_config(
        page_title="Semantic Search Chatbot", layout="wide"
    )

    st.title("🤖 Semantic Search Chatbot")
    st.markdown("Ask questions and get answers based on your document collection!")

    # Initialize session state for chat history
    if "messages" not in st.session_state:
        st.session_state.messages = []

    # Initialize chatbot
    if "chatbot" not in st.session_state:
        st.session_state.chatbot = ChatbotApp()

    # Display chat messages
    for message in st.session_state.messages:
        with st.chat_message(message["role"]):
            st.markdown(message["content"])

    # Chat input
    if prompt := st.chat_input("Ask a question..."):
        # Add user message to chat history
        st.session_state.messages.append({"role": "user", "content": prompt})

        # Display user message
        with st.chat_message("user"):
            st.markdown(prompt)

        # Display assistant response
        with st.chat_message("assistant"):
            with st.spinner("Thinking..."):
                response = st.session_state.chatbot.get_response(prompt)
                st.markdown(response)

        # Add assistant response to chat history
        st.session_state.messages.append({"role": "assistant", "content": response})

    # Sidebar with additional features
    with st.sidebar:
        st.header("Settings")

        # Clear chat button
        if st.button("Clear Chat History"):
            st.session_state.messages = []
            st.rerun()

        # Display system info
        st.header("System Info")
        st.info(
            f"Connected to Chroma collection: {os.getenv('CHROMA_DATABASE', 'Unknown')}"
        )

        # Display recent queries (if any)
        if st.session_state.messages:
            st.header("Recent Messages")
            for i, msg in enumerate(st.session_state.messages[-5:]):
                role_icon = "��" if msg["role"] == "user" else "🤖"
                st.text(f"{role_icon} {msg['content'][:50]}...")


if __name__ == "__main__":
    main()
