#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a financial asset
struct Asset {
    string name;
    double quantity;
    double pricePerUnit;
};

// Function to calculate the total value of an asset
double calculateAssetValue(const Asset& asset) {
    return asset.quantity * asset.pricePerUnit;
}

// Function to calculate the total portfolio value
double calculatePortfolioValue(const vector<Asset>& portfolio) {
    double totalValue = 0.0;
    for (const Asset& asset : portfolio) {
        totalValue += calculateAssetValue(asset);
    }
    return totalValue;
}

int main() {
    vector<Asset> portfolio;

    // Add assets to the portfolio
    portfolio.push_back({"Stock A", 100, 50.0});
    portfolio.push_back({"Stock B", 50, 75.0});
    portfolio.push_back({"Bonds", 2000, 1.5});

    // Calculate and display the portfolio value
    double portfolioValue = calculatePortfolioValue(portfolio);
    cout << "Portfolio Value: $" << portfolioValue << endl;

    return 0;
}