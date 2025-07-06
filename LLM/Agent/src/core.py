from email import message
from openai import OpenAI
import json
from typing import List, Dict, Any

from openai.types.chat import (
    ChatCompletionMessageToolCall,
    ChatCompletionToolParam,
    ChatCompletionSystemMessageParam,
    ChatCompletionMessageParam,
    ChatCompletionAssistantMessageParam,
    ChatCompletionToolMessageParam,
)
from src.utils import function_to_json
from src.tools import get_current_time, add, search_wikipedia, get_current_temperature

SYSTEM_PROMPT = """
    You are a AI Agent, the output should be the same language as input
    When user's question need to use tools,pls use the tools within the list
"""


class Agent:
    def __init__(
        self,
        client: OpenAI,
        model: str = "gpt-4o-mini",
        tools: List = [],
        verbose: bool = True,
    ):
        self.client = client
        self.model = model
        self.tools = tools
        self.verbose = verbose
        self.messages: List[ChatCompletionMessageParam] = [
            ChatCompletionSystemMessageParam(content=SYSTEM_PROMPT, role="system"),
        ]

    def get_tool_schema(self) -> List[ChatCompletionToolParam]:
        """
        Get the tool schema for the agent.
        """
        return [function_to_json(tool) for tool in self.tools]

    def handle_tool_call(
        self,
        tool_call: ChatCompletionMessageToolCall,
    ):
        """
        Handle a tool call.
        """
        function_name = tool_call.function.name
        function_args = json.loads(tool_call.function.arguments)
        function_call_content = eval(f"{function_name}(**{function_args})")
        return ChatCompletionToolMessageParam(
            role="tool", content=function_call_content, tool_call_id=tool_call.id
        )

    def get_completion(self, prompt: str) -> str | None:
        self.messages.append({"role": "user", "content": prompt})
        response = self.client.chat.completions.create(
            model=self.model,
            messages=self.messages,
            tools=self.get_tool_schema(),
        )
        if response.choices[0].message.tool_calls:
            self.messages.append(
                ChatCompletionAssistantMessageParam(
                    role="assistant",
                    content=response.choices[0].message.content,
                )
            )
            tool_list = []
            for tool_call in response.choices[0].message.tool_calls:
                self.messages.append(self.handle_tool_call(tool_call))
                tool_list.append(
                    [tool_call.function.name, tool_call.function.arguments]
                )
                if self.verbose:
                    print(
                        "Called tool: ", response.choices[0].message.content, tool_list
                    )
        self.messages.append(
            {"role": "assistant", "content": response.choices[0].message.content}
        )
        return response.choices[0].message.content
