#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<double> calculateDerivative(const vector<double>& coefficients) {
    vector<double> derivative;
    for (int i = 1; i < coefficients.size(); i++) {
        derivative.push_back(coefficients[i] * i);
    }
    return derivative;
}

void printPolynomial(const vector<double>& coefficients, bool isDerivative = false) {
    bool firstTerm = true;
    for (int i = coefficients.size() - 1; i >= 0; i--) {
        if (coefficients[i] != 0) {
            if (!firstTerm && coefficients[i] > 0) {
                cout << " + ";
            } else if (!firstTerm && coefficients[i] < 0) {
                cout << " - ";
            }

            if (abs(coefficients[i]) != 1 || i == 0) {
                cout << abs(coefficients[i]);
            }

            if (i > 0) {
                cout << "x";
                if (i > 1) {
                    cout << "^" << i;
                }
            }

            firstTerm = false;
        }
    }
    if (firstTerm) {
        cout << "0";
    }
    cout << endl;
}

int main() {
    int degree;
    cout << "Enter the degree of the polynomial (up to 5): ";
    cin >> degree;

    if (degree < 0 || degree > 5) {
        cout << "Invalid degree. Please enter a degree between 0 and 5." << endl;
        return 1;
    }

    vector<double> coefficients(degree + 1);
    for (int i = 0; i <= degree; i++) {
        cout << "Enter coefficient for x^" << i << ": ";
        cin >> coefficients[i];
    }

    cout << "Original polynomial: ";
    printPolynomial(coefficients);

    vector<double> derivative = calculateDerivative(coefficients);
    cout << "Derivative: ";
    printPolynomial(derivative, true);

    return 0;
}
