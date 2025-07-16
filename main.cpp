#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include "LinearRegression.h"

int main() {
    std::string filename;
    std::cout << "Enter CSV filename (e.g., data.csv): ";
    std::cin >> filename;

    std::pair<std::vector<std::vector<double>>, std::vector<double>> data = loadCSV(filename);
    std::vector<std::vector<double>> X = data.first;
    std::vector<double> Y = data.second;

    int num_features = X[0].size();
    LinearRegression model(num_features, 0.01, 1000);
    model.train(X, Y);

    std::cout << "\nEnter input values separated by space (" << num_features << " values): ";
    std::vector<double> input(num_features);
    for (int i = 0; i < num_features; ++i) {
        std::cin >> input[i];
    }
    std::cout << "Predicted output: " << model.predict(input) << "\n";

    return 0;
}
