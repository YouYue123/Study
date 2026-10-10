import json
import logging
import streamlit as st
from typing import List

from openai import OpenAI
from openai.types.chat import (
    ChatCompletionAssistantMessageParam,
    ChatCompletionMessageParam,
    ChatCompletionMessageToolCall,
    ChatCompletionMessageToolCallParam,
    ChatCompletionSystemMessageParam,
    ChatCompletionToolMessageParam,
    ChatCompletionToolParam,
)

from src.utils import function_to_json
from src.tools import get_current_time, search_wikipedia, get_current_temperature

SYSTEM_PROMPT = """
    You are a AI Agent, the output should be the same language as input
    When user's question need to use tools,pls use the tools within the list
"""


class StreamlitHandler(logging.Handler):
    """Custom logging handler for Streamlit"""
    
    def emit(self, record):
        try:
            msg = self.format(record)
            # Display in Streamlit
            st.text(msg)
        except Exception:
            self.handleError(record)


class Agent:
    def __init__(
        self,
        client: OpenAI,
        model: str = "gpt-4o-mini",
        tools: List = [],
        verbose: bool = True,
        log_level: str = "INFO",
        use_streamlit: bool = False,
    ):
        # Configure logger
        self.logger = logging.getLogger(f"Agent_{id(self)}")
        self.logger.setLevel(getattr(logging, log_level.upper()))
        
        # Clear existing handlers
        self.logger.handlers.clear()
        
        if use_streamlit:
            # Use Streamlit handler
            streamlit_handler = StreamlitHandler()
            formatter = logging.Formatter(
                '%(asctime)s - %(levelname)s - %(message)s'
            )
            streamlit_handler.setFormatter(formatter)
            self.logger.addHandler(streamlit_handler)
        else:
            # Use console handler
            console_handler = logging.StreamHandler()
            formatter = logging.Formatter(
                '%(asctime)s - %(name)s - %(levelname)s - %(message)s'
            )
            console_handler.setFormatter(formatter)
            self.logger.addHandler(console_handler)
        
        self.client = client
        self.model = model
        self.tools = tools
        self.verbose = verbose
        self.use_streamlit = use_streamlit
        self.messages: List[ChatCompletionMessageParam] = [
            ChatCompletionSystemMessageParam(
                content=SYSTEM_PROMPT,
                role="system",
            ),
        ]
        
        self.logger.info(f"Agent initialized with model: {model}, tools: {len(tools)}, verbose: {verbose}")

    def get_tool_schema(self) -> List[ChatCompletionToolParam]:
        """
        Get the tool schema for the agent.
        """
        self.logger.debug(f"Getting tool schema for {len(self.tools)} tools")
        return [function_to_json(tool) for tool in self.tools]

    def handle_tool_call(
        self,
        tool_call: ChatCompletionMessageToolCall,
    ) -> ChatCompletionToolMessageParam:
        """
        Handle a tool call.
        """
        function_name = tool_call.function.name
        function_args = json.loads(tool_call.function.arguments)
        
        self.logger.info(f"Handling tool call: {function_name} with args: {function_args}")
        
        # Function mapping for available tools
        function_map = {
            'get_current_time': get_current_time,
            'search_wikipedia': search_wikipedia,
            'get_current_temperature': get_current_temperature,
        }
        
        try:
            if function_name in function_map:
                function_call_content = function_map[function_name](**function_args)                
                self.logger.debug(f"Tool call {function_name} completed successfully with result {function_call_content}")
                return ChatCompletionToolMessageParam(
                    role="tool",
                    content=str(function_call_content),
                    tool_call_id=tool_call.id,
                )
            else:
                error_msg = f"Function '{function_name}' not found in available tools"
                self.logger.error(error_msg)
                return ChatCompletionToolMessageParam(
                    role="tool",
                    content=f"Error: {error_msg}",
                    tool_call_id=tool_call.id,
                )
        except Exception as e:
            self.logger.error(f"Error in tool call {function_name}: {str(e)}")
            return ChatCompletionToolMessageParam(
                role="tool",
                content=f"Error: {str(e)}",
                tool_call_id=tool_call.id,
            )

    def log_response_nicely(self, response, tool_list=None):
        """
        Log the OpenAI response in a nicely formatted way.
        """
        self.logger.info("="*60)
        self.logger.info("🤖 OPENAI RESPONSE")
        self.logger.info("="*60)
        
        # Log the main response content
        if response.choices[0].message.content:
            self.logger.info(f"📝 Response: {response.choices[0].message.content}")
        
        # Log tool calls if any
        if response.choices[0].message.tool_calls:
            self.logger.info(f"\n🔧 Tool Calls ({len(response.choices[0].message.tool_calls)}):")
            for i, tool_call in enumerate(response.choices[0].message.tool_calls, 1):
                self.logger.info(f"  {i}. Function: {tool_call.function.name}")
                self.logger.info(f"     Arguments: {tool_call.function.arguments}")
                if tool_list and i <= len(tool_list):
                    self.logger.info(f"     Result: {tool_list[i-1]}")
                self.logger.info("")
        
        # Log usage information
        if hasattr(response, 'usage') and response.usage:
            self.logger.info(f"📊 Usage:")
            self.logger.info(f"  - Prompt tokens: {response.usage.prompt_tokens}")
            self.logger.info(f"  - Completion tokens: {response.usage.completion_tokens}")
            self.logger.info(f"  - Total tokens: {response.usage.total_tokens}")
        
        self.logger.info("="*60)

    def get_completion(self, prompt: str) -> str | None:
        """
        Get completion from OpenAI API with tool calling support.
        Handles multi-turn conversations with tool calls.
        """
        self.logger.info(f"Getting completion for prompt: {prompt[:100]}{'...' if len(prompt) > 100 else ''}")
        
        # Add user message to conversation
        self.messages.append({"role": "user", "content": prompt})
        
        try:
            # Continue conversation until no more tool calls are needed
            while True:
                response = self.client.chat.completions.create(
                    model=self.model,
                    messages=self.messages,
                    tools=self.get_tool_schema(),
                    stream=False,
                )
                self.logger.debug(f"Received response from OpenAI API")
                
                # Add assistant message to conversation
                assistant_message = {
                    "role": "assistant",
                    "content": response.choices[0].message.content,
                }
                if response.choices[0].message.tool_calls:
                    assistant_message["tool_calls"] = response.choices[0].message.tool_calls
                
                self.messages.append(assistant_message)  # type: ignore
                
                # Handle tool calls if any
                if response.choices[0].message.tool_calls:
                    self.logger.info(f"Response contains {len(response.choices[0].message.tool_calls)} tool calls")
                    
                    tool_list = []
                    for tool_call in response.choices[0].message.tool_calls:
                        tool_result = self.handle_tool_call(tool_call)
                        self.messages.append(tool_result)
                        tool_list.append(
                            [tool_call.function.name, tool_call.function.arguments, tool_result["content"]]
                        )
                        if self.verbose:
                            self.logger.info(
                                f"Called tool: {tool_call.function.name} with result: {tool_result['content']}"
                            )
                    
                    # Log response nicely if verbose
                    if self.verbose:
                        self.log_response_nicely(response, tool_list)
                    
                    # Continue the conversation with tool results
                    continue
                else:
                    self.logger.debug("Response contains no tool calls")
                    # Log response nicely if verbose
                    if self.verbose:
                        self.log_response_nicely(response)
                    
                    # No more tool calls, conversation is complete
                    break
            
            self.logger.info("Completion completed successfully")
            return response.choices[0].message.content
            
        except Exception as e:
            self.logger.error(f"Error getting completion: {str(e)}")
            raise
