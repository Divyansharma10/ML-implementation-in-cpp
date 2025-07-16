#include "LinearRegression.h"
#include <iostream>
#include <fstream>
#include <sstream>

LinearRegression::LinearRegression(int num_features, double lr, int n_epochs)
    : weights(num_features, 1), bias(0.0), learning_rate(lr), epochs(n_epochs) {}

void LinearRegression::train(const std::vector<std::vector<double>>& X_vec, const std::vector<double>& Y_vec) {
    int n = X_vec.size();
    int features = weights.rows;

    Matrix X(n, features);
    Matrix Y = Matrix::fromVector(Y_vec);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < features; ++j)
            X.data[i][j] = X_vec[i][j];

    for (int epoch = 0; epoch < epochs; ++epoch) {
        Matrix predictions = X * weights;
        for (int i = 0; i < n; ++i)
            predictions.data[i][0] += bias;

        Matrix errors = predictions - Y;
        Matrix gradient = (X.transpose() * errors);

        for (int i = 0; i < weights.rows; ++i)
            weights.data[i][0] -= (learning_rate / n) * gradient.data[i][0];

        double db = 0.0;
        for (int i = 0; i < n; ++i)
            db += errors.data[i][0];
        bias -= (learning_rate / n) * db;

        if (epoch % 100 == 0) {
            std::cout << "Epoch " << epoch << ", Loss: " << compute_loss(X_vec, Y_vec) << "\n";
        }
    }
}

double LinearRegression::predict(const std::vector<double>& x) const {
    double result = bias;
    for (int i = 0; i < weights.rows; ++i)
        result += weights.data[i][0] * x[i];
    return result;
}

double LinearRegression::compute_loss(const std::vector<std::vector<double>>& X, const std::vector<double>& Y) const {
    double loss = 0.0;
    for (int i = 0; i < X.size(); ++i) {
        double error = predict(X[i]) - Y[i];
        loss += error * error;
    }
    return loss / X.size();
}

std::pair<std::vector<std::vector<double>>, std::vector<double>> loadCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<double>> X;
    std::vector<double> Y;
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<double> row;
        while (std::getline(ss, cell, ',')) {
            row.push_back(std::stod(cell));
        }
        Y.push_back(row.back());
        row.pop_back();
        X.push_back(row);
    }
    return {X, Y};
}
