import src.core import Agent
import src.tools import
import os
from openai import OpenAI

if __name__ == "__main__":
    client = OpenAI(api_key=os.getenv("OPENAI_API_KEY"),
    base_url="https://api.deepseek.com",)
