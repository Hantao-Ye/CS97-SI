#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#define PI 3.1415926

using namespace std;

double radius(double R, int n)
{
    double t = sin(PI / n);
    return t * R / (t + 1);
}

int main()
{
    int scene, n;
    double R;

    // freopen("input.txt", "r", stdin);

    cin >> scene;
    cout << fixed << setprecision(3);

    for (int i = 1; i <= scene; i++)
    {
        cin >> R >> n;

        cout << "Scenario #" << i << ":" << endl;
        cout << radius(R, n) << endl;

        if (i == scene)
            break;

        cout << endl;
    }
}