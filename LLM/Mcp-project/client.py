import asyncio
from fastmcp import Client

client = Client("server.py")

async def call_tool(name: str) -> str:
    async with client:
        result = await client.call_tool("greet", {"name": name})
        print(result)

asyncio.run(call_tool("YouYue"))
