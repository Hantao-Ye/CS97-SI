#include <iostream>
#include <cstdio>

using namespace std;

long long pow(long long base, int n)
{
    double ret = 1;
    while (n > 0)
    {
        if (n & 1)
            ret *= base;

        base *= base;
        n >>= 1;
    }
    return ret;
}

int main()
{
    // freopen("input.txt", "r", stdin);

    int N;
    cin >> N;

    while (N--)
    {
        unsigned int num;
        cin >> num;

        int digit = 0;
        while (num >= pow(2, digit))
        {
            if ((num - pow(2, digit)) % pow(2, digit + 1) == 0)
                break;

            digit++;
        }

        cout << num - pow(2, digit) + 1 << " " << num + pow(2, digit) - 1 << endl;
    }
}