#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

int main()
{
    double money = 0;
    double sum = 0;
    int month = 0;

    // freopen("input.txt", "r", stdin);

    while (cin >> money)
    {
        sum += money;
        month++;
    }

    cout<<fixed<<setprecision(2);
    cout << "$" << sum / month << endl;

    return 0;
}
