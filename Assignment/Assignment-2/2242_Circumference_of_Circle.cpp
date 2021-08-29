#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#define PI 3.141592653589793

using namespace std;

int main()
{
    double x1, x2, x3, y1, y2, y3;
    // freopen("input.txt", "r", stdin);

    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
        double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        double b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
        double c = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
        double S = 0.5f * abs((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));

        double R = a * b * c / (4 * S);

        double circum = 2 * PI * R;
        cout << fixed << setprecision(2);
        cout << circum << endl;
    }
}
