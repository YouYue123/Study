from fastmcp import FastMCP

weather_mcp = FastMCP("Weather Server")

@weather_mcp.tool
def get_weather(city: str) -> str:
    """Get weather for a given city."""
    return f"The weather in {city} is sunny."

if __name__ == "__main__":
    weather_mcp.run()