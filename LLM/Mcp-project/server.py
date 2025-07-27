import asyncio
import logging

from fastmcp import FastMCP
from fastmcp.server.middleware.logging import (
    LoggingMiddleware,
    StructuredLoggingMiddleware,
)
from fastmcp.server.middleware.timing import DetailedTimingMiddleware, TimingMiddleware
from servers.calendar_server import calendar_mcp
from servers.weather_server import weather_mcp

logging.basicConfig(level=logging.DEBUG)

main_mcp = FastMCP(
    "YouYue-MCP-Server",
    on_duplicate_tools="error",
    on_duplicate_resources="warn",
    on_duplicate_prompts="replace",
)


@main_mcp.tool
def greet(name: str) -> str:
    return f"Hello, {name}!"

async def setup():
    await main_mcp.import_server(calendar_mcp, prefix="calendar")
    await main_mcp.import_server(weather_mcp, prefix="weather")
    main_mcp.add_middleware(TimingMiddleware())

asyncio.run(setup())
