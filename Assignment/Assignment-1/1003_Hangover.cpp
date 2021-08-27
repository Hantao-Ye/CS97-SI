#include <iostream>
#include <cstdio>

using namespace std;

int cardsNum(double length)
{
    int cards = 2;
    while (length > 1.0f / cards)
    {
        length -= 1.0f / cards;
        cards++;
    }

    return cards - 1;
}

int main()
{
    double length;

    // freopen("input.txt", "r", stdin);

    while (cin >> length)
    {
        if (length <= 0)
            break;

        int cards = cardsNum(length);
        cout << cards << " card(s)" << endl;
    }

    return 0;
}