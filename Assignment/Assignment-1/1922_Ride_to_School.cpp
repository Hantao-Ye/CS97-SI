#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int n;
    int velocity, time;
    int temp;

    // freopen("input.txt", "r", stdin);
    while (cin >> n && n != 0)
    {
        int minArriveTime = __INT_MAX__;
        for (int i = 0; i < n; i++)
        {
            cin >> velocity >> time;

            if (time < 0)
                continue;
                
            temp = ceil(4500 * 3.6 / velocity + time);
            minArriveTime = min(minArriveTime, temp);
        }

        cout << minArriveTime << endl;
    }

    return 0;
}