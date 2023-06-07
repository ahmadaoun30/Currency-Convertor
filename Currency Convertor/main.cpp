//
//  main.cpp
//  Currency Convertor
//
//  Created by Ahmad Aoun.
//

#include <iostream>
#include <map>
#include <string>

// Function to convert the currency
double convertCurrency(double amount, double exchangeRate) {
    return amount * exchangeRate;
}

int main() {
    std::map<std::string, double> exchangeRates = {
        {"USD", 1.0},
        {"EUR", 0.85},
        {"GBP", 0.72},
        {"JPY", 109.53},
        {"AUD", 1.32},
        {"CAD", 1.21},
        {"CHF", 0.92},
        {"CNY", 6.39},
        {"INR", 73.01},
        {"NZD", 1.39},
        {"SEK", 8.58},
        {"MXN", 19.89},
        {"SGD", 1.35},
        {"HKD", 7.77},
        {"BRL", 5.26},
        {"RUB", 72.92},
        {"TRY", 8.44},
        {"ZAR", 14.50},
        {"AED", 3.67},
        {"KRW", 1133.83}
    };

    // input
    double amount;
    std::string fromCurrency, toCurrency;

    // Display menu
    std::cout << "Currency Converter\n";
    std::cout << "Available currencies:\n\n";
    int i = 1;
    for (const auto& pair : exchangeRates) {
        std::cout << i << ". " << pair.first << '\n';
        i++;
    }
    std::cout << "\nEnter First currency to convert from: ";
    std::cin >> fromCurrency;
    std::cout << "Enter Second currency to convert to: ";
    std::cin >> toCurrency;

    // Input validation
    if (exchangeRates.find(fromCurrency) == exchangeRates.end() || exchangeRates.find(toCurrency) == exchangeRates.end()) {
        std::cout << "Invalid currency.\n";
        return 0;
    }

    // Get amount to convert
    std::cout << "Enter the amount to convert: ";
    std::cin >> amount;

    // conversion
    double convertedAmount = convertCurrency(amount, exchangeRates[fromCurrency] / exchangeRates[toCurrency]);
    std::cout << amount << ' ' << fromCurrency << " is equivalent to " << convertedAmount << ' ' << toCurrency << '\n';

    return 0;
}

