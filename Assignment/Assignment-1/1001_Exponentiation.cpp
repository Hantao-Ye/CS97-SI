#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

string getPureNum(string base, int len);
string removeEndZero(string input);
string insertSeperator(string input, int sepIndex);
string power(string base, int exponent);
string stringMul(string x, string y);

int main()
{
    string base;
    int exponent;

    freopen("input.txt", "r", stdin);

    while (cin >> base >> exponent)
    {
        int len = 5;
        int pointIndex = 0;
        bool zeroEnd = true;

        for (int i = base.size() - 1; i >= 0; i--)
        {
            if (zeroEnd && base[i] != '0')
                zeroEnd = false;
            else if (zeroEnd && base[i] == '0')
                len--;

            if (base[i] == '.')
            {
                pointIndex = i;
                break;
            }
        }

        int sepIndex = (len - pointIndex) * exponent;
        string input = getPureNum(base, len);

        string output = removeEndZero(power(input, exponent));
        cout << insertSeperator(output, sepIndex) << endl;
    }
}

string insertSeperator(string input, int sepIndex)
{
    if (sepIndex <= input.length())
        input.insert(input.length() - sepIndex, ".");
    else
    {
        input.insert(0, "0");
        return insertSeperator(input, sepIndex);
    }

    return input;
}

// get the input without the integer separator
string getPureNum(string base, int len)
{
    string input = "";

    for (int i = 0; i < len + 1; i++)
    {
        if (base[i] == '.')
            continue;

        input.append(to_string(base[i]-'0'));
    }

    return input;
}

// remove the end zero in the result
string removeEndZero(string input)
{
    for (int i = input.length() - 1; i >= 0; i--)
        if (input[i] == '0')
            input.erase(input.end() - 1);
        else
            break;

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

    int res[x.length() + y.length() + 1] = {0};

    for (int i = x.length() - 1; i >= 0; i--)
    {
        int num_x = x[i] - '0';
        for (int j = y.length() - 1; j >= 0; j--)
        {
            int num_y = y[j] - '0';
            int sum = res[i + j + 1] + num_x * num_y;
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }

    string output = "";
    bool headZero = true;
    for (int i = 0; i < x.length() + y.length() + 1; i++)
    {
        if (headZero && res[i] == 0)
            continue;
        else if (res[i] != 0)
            headZero = false;

        output.append(to_string(res[i]));
    }

    return output;
}
