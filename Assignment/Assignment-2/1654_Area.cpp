#include <cstdio>
#include <iostream>

using namespace std;

int position_x[10] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int position_y[10] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};

int main()
{
    // freopen("input.txt", "r", stdin);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        string line = "";
        cin >> line;

        long long x = 0, y = 0, px = 0, py = 0, area = 0; // long could avoid something wrong in precision

        for (unsigned int j = 0; j < line.size() - 1; j++)
        {
            px = x + position_x[line[j] - '1'];
            py = y + position_y[line[j] - '1'];
            area += (px * y - x * py);

            x = px;
            y = py;
        }

        area = area < 0 ? -area : area;

        if (area % 2 == 0)
            cout << area / 2 << endl;
        else
            cout << area / 2 << ".5" << endl;
    }
}