from langchain_openai import ChatOpenAI
from langchain.prompts import PromptTemplate
from pydantic import SecretStr
from os import getenv
from dotenv import load_dotenv

load_dotenv()

template = """Question: {question}"""

prompt = PromptTemplate(template=template, input_variables=["question"])

llm = ChatOpenAI(
  api_key=SecretStr(getenv("OPENROUTER_API_KEY") or ""),
  base_url=getenv("OPENROUTER_BASE_URL"),
  model="gpt-4o-mini",
)

llm_chain = prompt | llm

question = "What is the capital of France?"

print(llm_chain.invoke({"question": question}))
