from fastmcp import FastMCP
from pydantic import BaseModel


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


if __name__ == "__main__":
    # This runs the server, defaulting to STDIO transport
    mcp.run()
