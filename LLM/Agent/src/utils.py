import inspect
from typing import Callable

from openai.types.chat import ChatCompletionToolParam
from openai.types.shared_params.function_definition import FunctionDefinition


def function_to_json(func: Callable) -> ChatCompletionToolParam:
    """
    Convert a function to a JSON-serializable dictionary.
    """
    type_map = {
        str: "string",
        int: "integer",
        float: "number",
        bool: "boolean",
        list: "array",
        dict: "object",
        type(None): "null",
    }
    try:
        signature = inspect.signature(func)
    except ValueError as e:
        raise ValueError(f"Function {func.__name__} has no signature: {e}")
    params = {}
    for param in signature.parameters.values():
        param_type_str = type_map.get(param.annotation, "unknown")
        params[param.name] = {
            "type": param_type_str,
        }
    
    required = [
        param.name
        for param in signature.parameters.values()
        if param.default == inspect.Parameter.empty
    ]
    return ChatCompletionToolParam(
        type="function",
        function=FunctionDefinition(
            name=func.__name__,
            description=func.__doc__ or "",
            parameters={
                "type": "object",
                "properties": params,
                "required": required,
            },
        )
    )