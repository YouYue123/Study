import datetime
import wikipedia
import requests

def get_current_time() -> str:
    """
    Get the current time.
    """
    current_datetime = datetime.datetime.now()
    formatted_time = current_datetime.strftime("%Y-%m-%d %H:%M:%S")
    return formatted_time

def search_wikipedia(query: str) -> str:
    """
    Search Wikipedia for information.
    """
    page_titles = wikipedia.search(query)
    summaries = []
    for page_title in page_titles[:3]:
        try:
            wiki_page = wikipedia.page(page_title, auto_suggest=False)
            summaries.append(f"**{wiki_page.title}**\n{wiki_page.summary}")
        except (
                wikipedia.exceptions.PageError,
                wikipedia.exceptions.DisambiguationError,
        ):
            pass
    if not summaries:
        return f"No Wikipedia page found for query: {query}"
    return "\n\n".join(summaries)


def get_current_temperature(latitude: float, longitude: float) -> str:
    """
    Get the current temperature at a given latitude and longitude.
    """
    url = f"https://api.open-meteo.com/v1/forecast?latitude={latitude}&longitude={longitude}&current_temperature=true"
    response = requests.get(url)
    data = response.json()
    return f"Current temperature: {data['current_temperature']}°C"