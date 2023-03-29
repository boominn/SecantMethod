#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    // Enter the function equation here
    return x * x - 2;
}

double secant(double x0, double x1, double tol) {
    double fx0 = f(x0);
    double fx1 = f(x1);
    double x2, fx2;
    int iter = 0;
    while (abs(fx1) > tol && iter < 100) {
        x2 = x1 - (fx1*(x1-x0))/(fx1-fx0);
        fx2 = f(x2);
        x0 = x1;
        fx0 = fx1;
        x1 = x2;
        fx1 = fx2;
        iter++;
    }
    return x2;
}

double bisection(double a, double b, double tol) {
    double fa = f(a);
    double fb = f(b);
    double c, fc;
    int iter = 0;
    while ((b-a)/2 > tol && iter < 100) {
        c = (a + b)/2;
        fc = f(c);
        if (fc == 0) {
            return c;
        } else if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
        iter++;
    }
    return c;
}

int main() {
    double x0, x1, tol, root;
    cout << "Enter x0: ";
    cin >> x0;
    cout << "Enter x1: ";
    cin >> x1;
    cout << "Enter tolerance: ";
    cin >> tol;
    root = secant(x0, x1, tol);
    cout << "The root of the equation using secant method is: " << root << endl;
    root = bisection(x0, x1, tol);
    cout << "The root of the equation using bisection method is: " << root << endl;
    return 0;
}
