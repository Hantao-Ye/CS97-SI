#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

void printSlice(int patrol, int row, int currentSlice);

int main()
{
    // freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int petrol;
        cin >> petrol;

        if (petrol > 9 || petrol < 0)
            continue;

        cout << "Scenario #" << i + 1 << ":" << endl;
        printSlice(petrol, 2 * petrol + 1, 1);

        if (i == n - 1)
            break;
        cout << endl;
    }
}

void printSlice(int petrol, int row, int currentSlice)
{
    if (currentSlice > row)
        return;

    cout << "slice #" << currentSlice << ":" << endl;
    int z_petrol = abs(petrol + 1 - currentSlice);
    for (int i = 0; i < row; i++)
    {
        int x_petrol = abs(petrol - i);
        for (int j = 0; j < row; j++)
        {
            int y_petrol = abs(petrol - j);
            if (x_petrol + y_petrol + z_petrol <= petrol)
                cout << (x_petrol + y_petrol + z_petrol);
            else
                cout << ".";
        }
        cout << endl;
    }

    printSlice(petrol, row, currentSlice + 1);
}