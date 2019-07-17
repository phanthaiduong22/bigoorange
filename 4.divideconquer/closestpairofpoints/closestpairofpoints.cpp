#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#define INF 1e9
using namespace std;
struct point
{
    double x, y;
};
bool xCompare(const point &p1, const point &p2)
{
    return p1.x < p2.x;
}
bool yCompare(const point &p1, const point &p2)
{
    return p1.y < p2.y;
}
double distance(point &p1, point &p2)
{
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    return sqrt(x * x + y * y);
}
double bruteForce(vector<point> &point_set, int left, int right)
{
    double min_dist = INF;
    for (int i = left; i < right; ++i)
        for (int j = i + 1; j < right; ++j)
            min_dist = min(min_dist, distance(point_set[i], point_set[j]));
    return min_dist;
}
double stripClosest(vector<point> &strip, double dist_min)
{
    sort(strip.begin(), strip.end(), yCompare);
    double min = dist_min;
    for (int i = 0; i < strip.size(); i++)
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < min; j++)
            if (distance(strip[i], strip[j]) < min)
                min = distance(strip[i], strip[j]);
    return min;
}
double minimalDistance(vector<point> &xPoints, int left, int right)
{
    if (right - left <= 3)
        return bruteForce(xPoints, left, right);
    int mid = (right + left) / 2;
    point midPoint = xPoints[mid];
    double dist_left = minimalDistance(xPoints, left, mid);
    double dist_right = minimalDistance(xPoints, mid + 1, right);
    double dist_min = min(dist_left, dist_right);
    vector<point> strip;
    for (int i = left; i < right; i++)
        if (abs(xPoints[i].x - midPoint.x) < dist_min)
            strip.push_back(xPoints[i]);
    return min(dist_min, stripClosest(strip, dist_min));
}
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        else
        {
            point p;
            vector<point> xPoints, yPoints;
            for (int i = 0; i < n; i++)
            {
                cin >> p.x >> p.y;
                xPoints.push_back(p);
                //yPoints.push_back(p);
            }
            sort(xPoints.begin(), xPoints.end(), xCompare);
            //sort(yPoints.begin(), yPoints.end(), yCompare);
            double result = minimalDistance(xPoints, 0, n);
            if ((result >= 10000))
                cout << "INFINITY" << endl;
            else
            {
                cout << fixed << setprecision(4) << result << endl;
            }
        }
    }
}