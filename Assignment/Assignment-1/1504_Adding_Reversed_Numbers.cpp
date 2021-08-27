#include <iostream>
#include <cstdio>

using namespace std;

int reverseNumber(int input);

int main()
{
    // freopen("input.txt", "r", stdin);

    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << reverseNumber(reverseNumber(a) + reverseNumber(b)) << endl;
    }
}

int reverseNumber(int input)
{
    int output = 0;

    while (input > 0)
    {
        output *= 10;
        output += input % 10;
        input /= 10;
    }

    return output;
}