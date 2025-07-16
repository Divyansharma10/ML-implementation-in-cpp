#include <iostream>
#include <vector>
#include "LinearRegression.h"

int main() {
    std::vector<std::vector<double>> X = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
        {5, 6}
    };
    std::vector<double> Y = {5, 8, 11, 14, 17};

    LinearRegression model(2, 0.01, 1000); // 2 features
    model.train(X, Y);

    std::cout << "\nEnter input values separated by space (e.g., 6 7): ";
    std::vector<double> input(2);
    std::cin >> input[0] >> input[1];
    std::cout << "Predicted output: " << model.predict(input) << "\n";

    return 0;
}
