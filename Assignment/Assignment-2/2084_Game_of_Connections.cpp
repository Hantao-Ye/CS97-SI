#include <iostream>
#include <cstdio>

using namespace std;

string longToString(long x)
{
    int n = 0;
    int temp = x;
    while (temp > 0)
    {
        n++;
        temp /= 10;
    }

    string output(n, '0');

    for (int i = n - 1; i >= 0; i--)
    {
        output[i] = x % 10 + '0';
        x /= 10;
    }

    return output;
}

string bigMultiply(string x, string y)
{
    if (!x.compare("0") || !y.compare("0"))
        return "0";

    string output(x.length() + y.length(), '0');

    for (int i = x.length() - 1; i >= 0; i--)
    {
        int num_x = x[i] - '0';
        for (int j = y.length() - 1; j >= 0; j--)
        {
            int num_y = y[j] - '0';
            int sum = output[i + j + 1] - '0' + num_x * num_y;
            output[i + j + 1] = '0' + sum % 10;
            output[i + j] += sum / 10;
        }
    }

    output.erase(0, output.find_first_not_of('0'));

    return output;
}

string bigDivide(string number, int divisor)
{
    string output = "";

    int index = 0;
    int temp = number[index] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++index] - '0');

    while (number.size() > index)
    {
        output += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++index] - '0';
    }

    if (output.length() == 0)
        return "0";

    return output;
}

string ways(int n)
{
    string output = "1";

    for (int i = 0; i < n; i++)
    {
        string multiply = longToString(2 * (2 * i + 1));
        output = bigMultiply(output, multiply);
        int divisor = i + 2;
        output = bigDivide(output, divisor);
    }

    return output;
}

int main()
{
    int n;
    // freopen("input.txt", "r", stdin);
    while (cin >> n && n != -1)
    {
        cout << ways(n) << endl;
    }
    return 0;
}
