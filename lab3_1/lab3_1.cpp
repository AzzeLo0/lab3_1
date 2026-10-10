#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
// Обчислення e^(-x) за рядом Тейлора
double expTaylor(double x, double eps)
{
    double element = 1;
    double sum = 1;
    int k = 1;
    while (fabs(element) > eps)
    {
        element = element * (-x) / k;
        sum = sum + element;
        k = k + 1;
    }
    return sum;
}
int main()
{
    cout << "Laboratory work 4, variant 23" << endl;
    cout << "Student: Sarzhevskyi Daniil Oleksandrovych" << endl;
    cout << "Group: IPZ-12(6)" << endl;
    double xMin, xMax, step, eps;
    double y, yStandard, error;
    cout << "\nTASK 1" << endl;
    cout << "Enter minimum x: ";
    cin >> xMin;
    cout << "Enter maximum x: ";
    cin >> xMax;
    cout << "Enter step: ";
    cin >> step;
    cout << "Enter eps: ";
    cin >> eps;
    if (step <= 0)
    {
        cout << "Incorrect step" << endl;
        return 0;
    }
    if (eps < 1e-6 || eps > 1e-2)
    {
        cout << "Incorrect eps" << endl;
        return 0;
    }
    cout << fixed << setprecision(8);
    cout << endl;
    cout << setw(10) << "x"
        << setw(20) << "y"
        << setw(20) << "standard"
        << setw(20) << "error" << endl;
    for (double x = xMin; x <= xMax; x = x + step)
    {
        if (x >= -2 && x <= 0)
        {
            y = expTaylor(x + 2, eps)
                + expTaylor(x / 3.0, eps);
            yStandard = exp(-(x + 2))
                + exp(-x / 3.0);
            error = fabs(fabs(y) - fabs(yStandard));
            cout << setw(10) << x
                << setw(20) << y
                << setw(20) << yStandard
                << setw(20) << error << endl;
        }
        else if (x > 0 && x < 2)
        {
            y = expTaylor(x - 5, eps)
                - expTaylor(x * x, eps);
            yStandard = exp(-(x - 5))
                - exp(-(x * x));
            error = fabs(fabs(y) - fabs(yStandard));
            cout << setw(10) << x
                << setw(20) << y
                << setw(20) << yStandard
                << setw(20) << error << endl;
        }
        else
        {
            cout << setw(10) << x
                << "   function is not defined" << endl;
        }
    }
    return 0;
}