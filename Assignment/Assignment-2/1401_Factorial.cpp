#include <iostream>
#include <cstdio>

using namespace std;

unsigned int zeroEnd(unsigned N)
{
    unsigned int output = 0;
    unsigned int base = 5;
    while (N >= base)
    {
        output += N / base;
        base *= 5;
    }
    return output;
}

int main()
{
    unsigned int T, N;

    // freopen("input.txt", "r", stdin);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cout << zeroEnd(N) << endl;
    }

    return 0;
}