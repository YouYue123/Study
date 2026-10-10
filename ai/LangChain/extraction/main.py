import logging
from typing import Optional

from langchain_core.messages import BaseMessage
from env import set_env
from langchain_core.prompts import ChatPromptTemplate, MessagesPlaceholder
from pydantic import BaseModel, Field
from langchain.chat_models import init_chat_model
from langchain_core.utils.function_calling import tool_example_to_messages


set_env()
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)


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
    height_in_feet: Optional[str] = Field(
        default=None,
        description="Height measured in feet",
    )


# Define a custom prompt to provide instructions and any additional context.
# 1) You can add examples into the prompt template to improve extraction quality
# 2) Introduce additional parameters to take context into account (e.g., include metadata
#    about the document from which the text was extracted.)
prompt_template = ChatPromptTemplate.from_messages(
    [
        (
            "system",
            "You are an expert extraction algorithm. "
            "Only extract relevant information from the text. "
            "If you do not know the value of an attribute asked to extract, "
            "return null for the attribute's value.",
        ),
        # Please see the how-to about improving performance with
        # reference examples.
        # MessagesPlaceholder('examples'),
        ("human", "{text}"),
    ]
)

llm = init_chat_model("gpt-4o-mini", model_provider="openai")

structured_llm = llm.with_structured_output(schema=Person)

text = "Alan Smith is 6 feet tall and has blond hair."
prompt = prompt_template.invoke({"text": text})
response = structured_llm.invoke(prompt)

logging.info(response)

text = "John Doe is 5 feet 10 inches tall and has brown hair."
prompt = prompt_template.invoke({"text": text})
response = structured_llm.invoke(prompt)

logging.info(response)


class Data(BaseModel):
    """Extracted data about people."""

    # Creates a model so that we can extract multiple entities.
    people: list[Person]


structured_llm = llm.with_structured_output(schema=Data)
text = "My name is Jeff, my hair is black and i am 6 feet tall. Anna has the same color hair as me."
prompt = prompt_template.invoke({"text": text})
response = structured_llm.invoke(prompt)

logging.info(response)


examples = [
    (
        "The ocean is vast and blue. It's more than 20,000 feet deep.",
        Data(people=[]),
    ),
    (
        "Fiona traveled far from France to Spain.",
        Data(
            people=[
                Person(name="Fiona", height_in_meters=None, hair_color=None),
            ]
        ),
    ),
]

messages: list[BaseMessage] = []

for txt, tool_call in examples:
    if tool_call.people:
        # This final message is optional for some providers
        ai_response = "Detected people."
    else:
        ai_response = "Detected no people."
    messages.extend(
        tool_example_to_messages(txt, [tool_call], ai_response=ai_response),
    )
    messages.extend(
        tool_example_to_messages(
            txt,
            [tool_call],
            ai_response=ai_response,
        )
    )


for message in messages:
    message.pretty_print()


message_no_extraction = {
    "role": "user",
    "content": "The Fiona is large, It's more than 20,000 feet deep.",
}

logging.info("No examples")
structured_llm = llm.with_structured_output(schema=Data)
response = structured_llm.invoke([message_no_extraction])
logging.info(response)

logging.info("With examples")
response = structured_llm.invoke(messages + [message_no_extraction])
logging.info(response)



