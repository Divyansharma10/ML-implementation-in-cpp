# Multivariable Linear Regression in C++

This project implements a multivariable linear regression model in C++ using matrix operations and gradient descent. It supports dynamic training from a CSV file and allows interactive prediction after training.

## Features

* Train on data loaded from a CSV file
* Matrix-based gradient descent optimization
* Custom matrix class with no external dependencies
* Console-based input for real-time prediction

## CSV Format

The input CSV should contain one sample per line, where:

* Each line contains multiple feature values followed by the target value.
* Feature values and the label should be comma-separated.

Example:

```
1,2,5
2,3,8
3,4,11
4,5,14
5,6,17
```

This represents a dataset with 2 features and 1 target variable.

## Model

The model fits the linear relationship:

```
y = w1*x1 + w2*x2 + ... + wn*xn + b
```

where `w` are the weights and `b` is the bias.

## Compilation

Use a C++17-compatible compiler. Example using `g++`:

```bash
g++ -std=c++17 main.cpp LinearRegression.cpp Matrix.cpp -o regression
```

## Usage

After compiling, run the program and follow the prompt:

```bash
./regression
```

Example interaction:

```
Enter CSV filename (e.g., data.csv): data.csv
Enter input values separated by space (2 values): 6 7
Predicted output: 20
```

## Requirements

* C++17 or later
* No external libraries required
