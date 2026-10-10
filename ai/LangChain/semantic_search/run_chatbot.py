#!/usr/bin/env python3
"""
Script to run the Streamlit chatbot
"""
import subprocess
import sys
import os
from env import set_env
set_env()

def main():
    # Change to the directory containing the chatbot
    script_dir = os.path.dirname(os.path.abspath(__file__))
    os.chdir(script_dir)
    
    # Run streamlit
    try:
        subprocess.run([
            sys.executable, "-m", "streamlit", "run", "chatbot.py",
            "--server.port", "8501",
            "--server.address", "localhost"
        ], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error running Streamlit: {e}")
        sys.exit(1)
    except KeyboardInterrupt:
        print("\nChatbot stopped by user")
        sys.exit(0)

if __name__ == "__main__":
    main() 