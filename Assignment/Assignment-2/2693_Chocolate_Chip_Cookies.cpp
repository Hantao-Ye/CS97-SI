#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

#define EPS 1e-6

using namespace std;

class Point
{
public:
    double x;
    double y;

    Point(double x = 0, double y = 0)
    {
        this->x = x;
        this->y = y;
    }
};

double distancePoint(Point p1, Point p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

bool inCircle(Point p, Point c)
{
    double d = (p.x - c.x) * (p.x - c.x) + (p.y - c.y) * (p.y - c.y);
    if (d > 6.25 + EPS)
        return false;
    else
        return true;
}

Point circle(Point p1, Point p2)
{
    Point mid = Point((p1.x + p2.x) / 2.0, (p1.y + p2.y) / 2.0);
    Point diff = Point(p2.x - p1.x, p2.y - p1.y);

    double d = distancePoint(p1, p2);
    Point unit = Point(-diff.y / d, diff.x / d);

    double length = sqrt(6.25 - d * d / 4.0);

    Point c = Point(mid.x + length * unit.x, mid.y + length * unit.y);
    return c;
}

int main()
{
    // freopen("input.txt", "r", stdin);

    Point point;
    vector<Point> points;
    while (cin >> point.x >> point.y)
    {
        points.push_back(point);
    }

    int maxChocolate = 0;
    int size = points.size();
    for (int i = 0; i < size; i++)
    {
        Point p1 = points[i];
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                maxChocolate = max(1, maxChocolate);
                continue;
            }

            Point p2 = points[j];
            double d = distancePoint(p1, p2);
            if (d > 5 + EPS)
                continue;

            Point c = circle(p1, p2);

            int temp = 0;
            for (int k = 0; k < size; k++)
            {
                if (inCircle(points[k], c))
                    temp++;
            }
            maxChocolate = max(temp, maxChocolate);
        }
    }

    cout << maxChocolate << endl;
}