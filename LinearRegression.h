#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include <vector>
#include <string>
#include <utility>
#include "Matrix.h"

class LinearRegression {
private:
    Matrix weights;
    double bias;
    double learning_rate;
    int epochs;

public:
    LinearRegression(int num_features, double lr = 0.01, int n_epochs = 1000);
    void train(const std::vector<std::vector<double>>& X, const std::vector<double>& Y);
    double predict(const std::vector<double>& x) const;
    double compute_loss(const std::vector<std::vector<double>>& X, const std::vector<double>& Y) const;
};

// 👇 Add this declaration below
std::pair<std::vector<std::vector<double>>, std::vector<double>> loadCSV(const std::string& filename);

#endif // LINEAR_REGRESSION_H
