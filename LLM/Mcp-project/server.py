import asyncio
import time
from fastmcp import FastMCP
from mcp.types import Request
from pydantic import BaseModel
from starlette.responses import PlainTextResponse


class Config(BaseModel):
    theme: str
    version: str


class UserProfile(BaseModel):
    id: str
    name: str
    status: str


mcp = FastMCP(
    "YouYue-MCP-Server",
    on_duplicate_tools="error",
    on_duplicate_resources="warn",
    on_duplicate_prompts="replace",
)


@mcp.tool()
def greet(name: str) -> str:
    return f"Hello, {name}!"


@mcp.tool()
def multiply(a: float, b: float) -> float:
    """
    Multiply two numbers together.
    """
    return a * b


@mcp.tool(tags={"public", "utility"})
def public_tool() -> str:
    return "This tool is public and can be used by anyone."


@mcp.tool(tags={"internal", "admin"})
def admin_tool() -> str:
    return "This tool is only available to administrators."


@mcp.tool(tags={"deprecated"})
def deprecated_tool() -> str:
    return "This tool is deprecated and will be removed in the future."


def cpu_intensive_task(data: str) -> str:
    time.sleep(3)
    return f"CPU-intensive task completed {data}"


@mcp.tool
async def wrapped_cpu_intensive_task(data: str) -> str:
    """
    Wraps a CPU-intensive task in a function that can be called by the client.
    """
    return await asyncio.to_thread(cpu_intensive_task, data)


@mcp.resource("data://config")
def config() -> Config:
    """Provides the application configuration."""
    return Config(theme="dark", version="1.0.0")


@mcp.resource("data://data")
def data() -> list[float]:
    """Provides the data to be analysed."""
    return [1, 2, 3, 4, 5]


@mcp.resource("users://{user_id}/profie")
def get_user_profile(user_id: str) -> UserProfile:
    """Retrieves a user's profile by ID."""
    return UserProfile(id=user_id, name=f"User {user_id}", status="active")


@mcp.prompt
def analyze_data(data: list[float]) -> str:
    """Creates a prompt asking for analysis of numerical data."""
    formatted_data = ", ".join(str(value) for value in data)
    return f"Analyse the these data points: {formatted_data}"


@mcp.custom_route("/health", methods=["GET"])
async def health_check(_: Request) -> PlainTextResponse:
    return PlainTextResponse("OK", status_code=200)


if __name__ == "__main__":
    # This runs the server, defaulting to STDIO transport
    mcp.run()
