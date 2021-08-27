#include <iostream>

using namespace std;

int main()
{
    int num = 0, output = 1;
    cin >> num;

    for (int i = 1; i <= (num / 2) + 1; i++)
    {
        int sum = 0;
        for (int j = i; j <= (num / 2) + 1; j++)
        {
            sum += j;
            if (sum == num)
            {
                output++;
                break;
            }
            else if (sum > num)
                break;
        }
    }

    cout << output << endl;
}