from enum import Enum
import logging
from typing import Optional
from langchain_core.prompts import ChatPromptTemplate
from langchain_openai import ChatOpenAI
from pydantic import BaseModel, Field
from langchain.chat_models import init_chat_model
from env import set_env

set_env()
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

tagging_prompt = ChatPromptTemplate.from_template(
    """
Extract the desired information from the following passage.

Only extract the properties mentioned in the 'Classification' function.

Passage:
{input}
"""
)
llm = init_chat_model("gpt-4o-mini", model_provider="openai")


class Sentiment(str, Enum):
    HAPPY = "happy"
    NEUTRAL = "neutral"
    SAD = "sad"


class Language(str, Enum):
    EN = "en"
    ZH = "zh"
    JA = "ja"
    KO = "ko"
    FR = "fr"
    DE = "de"
    IT = "it"
    ES = "es"
    PT = "pt"


class Classification(BaseModel):
    sentiment: Sentiment
    aggresiveness: int = Field(description="The aggresiveness of the text", default=0)
    language: Language


structured_llm = llm.with_structured_output(Classification)

inp = "Estoy increiblemente contento de haberte conocido! Creo que seremos muy buenos amigos!"
prompt = tagging_prompt.invoke({"input": inp})
response = structured_llm.invoke(prompt)

logging.info(response)

inp = "Estoy muy enojado con vos! Te voy a dar tu merecido!"
prompt = tagging_prompt.invoke({"input": inp})
response = structured_llm.invoke(prompt)

logging.info(response)

inp = "我爱你"
prompt = tagging_prompt.invoke({"input": inp})
response = structured_llm.invoke(prompt)

logging.info(response)

tagging_prompt = ChatPromptTemplate.from_template(
    """
    Extract the desired information from the following passage.

    Only extract the properties mentioned in the 'Classification' function.

    Passage:
    {input}
    """
)

llm = ChatOpenAI(temperature=0, model="gpt-4o-mini").with_structured_output(
    Classification
)
inp = "Estoy increiblemente contento de haberte conocido! Creo que seremos muy buenos amigos!"
prompt = tagging_prompt.invoke({"input": inp})
llm.invoke(prompt)
logging.info(response)

from pydantic import BaseModel, Field


class Person(BaseModel):
    # ^ Doc-string for the entity Person.
    # This doc-string is sent to the LLM as the description of the schema Person,
    # and it can help to improve extraction results.
    # Note that:
    # 1. Each field is an `optional` -- this allows the model to decline to extract it!
    # 2. Each field has a `description` -- this description is used by the LLM.
    # Having a good description can help improve extraction results.
    name: Optional[str] = Field(
        default=None,
        description="The name of the person",
    )
    hair_color: Optional[str] = Field(
        default=None,
        description="The color of the person's hair if known",
    )
    height_in_meters: Optional[str] = Field(
        default=None,
        description="Height measured in meters",
    )
