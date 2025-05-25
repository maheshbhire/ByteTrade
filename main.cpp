#include <bits/stdc++.h>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <thread>
#include "functions.h"
#include "curl_function.h"
using namespace std;

int main() {
    string ticker;
    cout << "\nEnter Ticker symbol of a company: ";
    cin >> ticker;

    int length = 300;
    float thresholdExtraHigh = 4.0;
    // Initialize additional thresholds (matching Pine Script defaults)
    float thresholdHigh = 2.5;
    float thresholdMedium = 1.0;
    float thresholdNormal = -0.5;

    while (true) {
        Json::Value config;
        ifstream config_file("config.json", ifstream::binary);

        if (!config_file.is_open()) {
            cerr << "Failed to open config file." << endl;
            return 1;
        }

        config_file >> config;
        config_file.close();

        string api_key = config["api_key"].asString();
        string name, exchange, currency, ans;
        float open, high, low, close, volume, change, price;
        int amount;

        price = stof(get_price(ticker, api_key));

        Json::Value stock_data = get_stock_quote(ticker, api_key);
        if (!stock_data.empty()) {
            name = stock_data["name"].asString();
            exchange = stock_data["exchange"].asString();
            currency = stock_data["currency"].asString();
            open = stof(stock_data["open"].asString());
            high = stof(stock_data["high"].asString());
            low = stof(stock_data["low"].asString());
            close = stof(stock_data["close"].asString());
            volume = stof(stock_data["volume"].asString());
            change = stof(stock_data["change"].asString());
        } else {
            cerr << "Failed to fetch stock quote." << endl;
            return 1;
        }

        vector<HistoricalData> historical_data = get_historical_data(ticker, api_key, length);

        static TradingState state;
        // Set additional thresholds in state
        state.thresholdHigh = thresholdHigh;
        state.thresholdMedium = thresholdMedium;
        state.thresholdNormal = thresholdNormal;

        update_trading_state(historical_data, state, price, thresholdExtraHigh);

        print_data(name, exchange, currency, open, high, low, close, volume, change, price);
        ProfitLoss(open, close, name);

        execute_trading_strategy(state, price, ans, amount);

        this_thread::sleep_for(chrono::milliseconds(3000));
    }

    return 0;
}