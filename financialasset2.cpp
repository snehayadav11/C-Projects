#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Structure to represent a financial asset
struct Asset {
    string name;
    double quantity;
    double purchasePrice;
};

// Function to calculate the total value of an asset
double calculateAssetValue(const Asset& asset, double currentPrice) {
    return asset.quantity * currentPrice;
}

// Function to calculate portfolio value
double calculatePortfolioValue(const vector<Asset>& portfolio, const vector<double>& currentPrices) {
    double totalValue = 0.0;
    for (size_t i = 0; i < portfolio.size(); ++i) {
        totalValue += calculateAssetValue(portfolio[i], currentPrices[i]);
    }
    return totalValue;
}

// Function to load asset data from a file
vector<Asset> loadPortfolioFromFile(const string& fileName) {
    vector<Asset> portfolio;
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string name;
            double quantity, purchasePrice;
            if (iss >> name >> quantity >> purchasePrice) {
                portfolio.push_back({name, quantity, purchasePrice});
            }
        }
        file.close();
    }
    return portfolio;
}

int main() {
    vector<Asset> portfolio;
    vector<double> currentPrices;

    // Load portfolio from a file (name quantity purchasePrice)
    portfolio = loadPortfolioFromFile("portfolio.txt");

    // Simulated current prices for demonstration purposes
    currentPrices = {55.0, 80.0, 1.2}; // Replace with actual data

    // Calculate and display portfolio value
    double portfolioValue = calculatePortfolioValue(portfolio, currentPrices);
    cout << fixed << setprecision(2);
    cout << "Portfolio Value: $" << portfolioValue << endl;

    return 0;
}