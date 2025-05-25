Trading-App

Welcome to the Trading App! This C++ application provides real-time stock trading insights by fetching data from the Twelve Data API and applying a sophisticated Volume Climax Indicator (VCI) strategy. It helps users make informed decisions on buying and selling stocks by generating signals based on volume spikes and price breakouts, with built-in trade management features like stop-loss, take-profit, and partial exits.

The app integrates a Pine Script-inspired strategy originally developed for TradingView, adapted for real-time execution in C++. This project was developed by Mahesh Hire as of September 11, 2024.



Table of Contents





Purpose of Implementation



Features



Project Implementation





Project Structure



Built With



Getting Started





Prerequisites



Installation



Usage



Authors



Show Your Support

Purpose of Implementation

The Trading App aims to empower users with a powerful tool for real-time stock trading decisions. It combines real-time data monitoring with a volume-based trading strategy to provide actionable buy/sell signals while managing risk through stop-loss and take-profit mechanisms.

Features





Real-Time Data Monitoring: Continuously fetches stock prices and volume data using the Twelve Data API.



Volume Climax Indicator (VCI) Strategy: Identifies high-volume bars to set key price levels (LOW and HIGH) for signal generation.



Buy/Sell Signal Generation: Generates buy signals when the price breaks above the HIGH of a high-volume bar, with confirmation logic to reduce false signals.



Trade Management:





Stop-loss set at 1% below the LOW.



Take-profit set at 2x the stop-loss distance above the HIGH.



Partial exit of 50% of the position at an intermediate profit level.



Profit/Loss Calculation: Displays the percentage profit or loss based on the day’s open and close prices.



Cost Calculation: Allows users to calculate the cost of buying/selling a specified amount of stock.



Alerts: Prints actionable alerts to the console for buy signals, confirmed entries, partial exits, and stop-loss hits.

Project Implementation

Project Structure

The project is organized into several files, each serving a specific purpose:





curl_functions.hpp and curl_functions.cpp: Handle HTTP requests to the Twelve Data API.





get_price(): Fetches the current stock price.



get_stock_quote(): Retrieves detailed stock data (open, high, low, close, volume).



get_historical_data(): Fetches historical data for volume analysis.



functions.hpp and functions.cpp: Contain the core trading logic.





ProfitLoss(): Calculates and displays profit/loss percentage.



wantTransact(): Manages user interaction for buying/selling and cost calculation.



print_data(): Displays stock data.



calculate_mean() and calculate_stddev(): Compute volume metrics for VCI analysis.



update_trading_state(): Identifies high-volume bars and sets key levels (LOW, HIGH, SL, TP).



execute_trading_strategy(): Executes the VCI-based trading strategy (buy/sell signals, trade management).



main.cpp: The main entry point, orchestrating data fetching, strategy execution, and user interaction.



config.json: Stores the API key for Twelve Data API access (not tracked in git).



.gitignore: Excludes compiled files and sensitive data (e.g., config.json).



compile-and-run.sh: A script to simplify compilation and execution.

Built With





C++ STL (Standard Template Library): For core programming logic.



libcurl: For making HTTP requests to the Twelve Data API.



JsonCpp: For parsing JSON responses from the API.

Getting Started

Prerequisites

Before running the Trading App, ensure you have the following installed:





C++ Compiler (g++): For compiling the code.



libcurl: For HTTP requests.





Install on Ubuntu: sudo apt-get install libcurl4-openssl-dev



JsonCpp: For JSON parsing.





Install on Ubuntu: sudo apt-get install libjsoncpp-dev



Twelve Data API Key: Sign up at Twelve Data to obtain an API key.

Installation





Clone the repository:

git clone https://github.com/maheshbhire/trading-app-in-cpp.git



Navigate to the project directory:

cd trading-app-in-cpp



Create a config.json file in the project root with your API key:

{
    "api_key": "your_twelve_data_api_key_here"
}



Compile the application:

g++ -o output/trade main.cpp curl_functions.cpp functions.cpp -lcurl -ljsoncpp

Or use the provided script:

./compile-and-run.sh

Usage





Run the compiled application:

./output/trade



Enter the ticker symbol of a company (e.g., AAPL for Apple Inc.) when prompted.



The app will:





Fetch real-time stock data and historical data for volume analysis.



Display stock details (price, volume, etc.) and profit/loss percentage.



Generate buy/sell signals based on the VCI strategy.



Manage trades with stop-loss, take-profit, and partial exits.



Print alerts for trading actions (buy, sell, partial exit, stop-loss hit).



The app updates every 3 seconds, providing continuous real-time insights.

Authors 👤





Mahesh Hire





LinkedIn



GitHub



Email: maheshhire002@gmail.com

Show Your Support ⭐️⭐️

If you find this project helpful or interesting, please consider giving it a star on GitHub!