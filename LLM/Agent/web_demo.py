import streamlit as st
from src.core import Agent
from src.tools import get_current_temperature, get_current_time, search_wikipedia
from openai import OpenAI

st.set_page_config(
    page_title="YY Agent Demo", layout="centered", initial_sidebar_state="auto"
)

client = OpenAI(
    base_url="https://openrouter.ai/api/v1",
)


@st.cache_resource
def load_agent():
    return Agent(
        client=client,
        model="deepseek/deepseek-chat-v3-0324:free",
        tools=[
            get_current_time,
            get_current_temperature,
            search_wikipedia,
        ],
        verbose=True,
        use_streamlit=False,
    )


agent = load_agent()

st.title("Welcome!")
st.markdown("Input:")
if "message" not in st.session_state:
    st.session_state.messages = []

for message in st.session_state.messages:
    with st.chat_message(message["role"]):
        st.markdown(message["content"])

if prompt := st.chat_input("What can I do for you"):
    st.chat_message("user").markdown(prompt)
    st.session_state.messages.append({"role": "user", "content": prompt})
    with st.spinner("Thinking"):
        response = agent.get_completion(prompt)
    with st.chat_message("assistant"):
        st.markdown(response)
    st.session_state.messages.append({"role": "assistent", "content": response})
