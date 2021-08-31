#include <iostream>
#include <cstdio>

using namespace std;

string insertSeperator(string input, int sepIndex);
string power(string base, int exponent);
string stringMul(string x, string y);

int main()
{
    string base;
    int exponent;

    // freopen("input.txt", "r", stdin);

    while (cin >> base >> exponent)
    {
        int pointIndex = 0;

        while (base[base.length() - 1] == '0')
            base.erase(base.length() - 1);

        pointIndex = base.find('.');
        base.erase(pointIndex, 1);

        string output = power(base, exponent);

        int sepIndex = (base.length() - pointIndex) * exponent;
        cout << insertSeperator(output, sepIndex) << endl;
    }
}

string insertSeperator(string input, int sepIndex)
{
    if (sepIndex == 0)
        return input;
    else if (sepIndex <= input.length())
        input.insert(input.length() - sepIndex, ".");
    else
    {
        input.insert(0, "0");
        return insertSeperator(input, sepIndex);
    }

    return input;
}

// calculate the base with the power of exponent
string power(string base, int exponent)
{
    string res = "1";
    while (exponent > 0)
    {
        if (exponent & 1)
            res = stringMul(res, base);

        base = stringMul(base, base);
        exponent >>= 1;
    }
    return res;
}

// calculate the multiplication of x and y
string stringMul(string x, string y)
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
            output[i + j + 1] = sum % 10 + '0';
            output[i + j] += sum / 10;
        }
    }

    output.erase(0, output.find_first_not_of('0'));

    return output;
}
