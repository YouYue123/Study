from fastmcp import FastMCP

calendar_mcp = FastMCP("Calendar Server")

@calendar_mcp.tool
def get_calendar_events(date: str) -> list[str]:
    """Get calendar events for a given date."""
    return ["Event 1", "Event 2", "Event 3"]
