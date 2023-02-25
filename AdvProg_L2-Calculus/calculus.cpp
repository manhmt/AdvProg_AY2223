#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    double result = 1.0;
    double term = 1.0;
    int sign = -1;
    for (int i = 1; i <= 10; i++) {
        result += sign * term;
        sign = -sign;
        term *= x * x / (2 * i - 1) / (2 * i);
    }
    return result;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double result = 0.0;
    double term = x;
    int sign = 1;
    for (int i = 1; i <= 10; i++) {
        result += sign * term;
        sign = -sign;
        term *= x * x / (2 * i) / (2 * i + 1);
    }
    return result;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    double result = x;
    double eps = 1e-8; // Set the tolerance for the iteration
    while (fabs(result * result - x) > eps) {
        result = (result + x / result) / 2;
    }
    return result;
}