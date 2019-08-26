#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef struct block
{
    int dimension[3];
    block(int x, int y, int z)
    {
        dimension[0] = x;
        dimension[1] = y;
        dimension[2] = z;
    }
    bool Canstack(const struct block &other)
    {
        if (dimension[0] < other.dimension[0] && dimension[1] < other.dimension[1])
            return true;
        return false;
    }
    bool operator<(const struct block &other) const
    {
        for (int i = 0; i < 3; i++)
            if (dimension[i] > other.dimension[i])
                return true;
            else if (dimension[i] < other.dimension[i])
                return false;
        return true;
    }
} block;
int LIS(vector<block> a)
{
    int res = 0;
    vector<int> height(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        height[i] = a[i].dimension[2];
        for (int j = 0; j < i; j++)
        {
            if (a[i].Canstack(a[j]))
            {
                height[i] = max(height[i], a[i].dimension[2] + height[j]);
            }
        }
        res = max(res, height[i]);
    }
    return res;
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int n, j = 0;
    while (cin >> n)
    {
        if (n == 0)
            break;
        cout << "Case " << j + 1 << ": maximum height = ";
        j++;
        vector<block> a;
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            a.push_back({x, y, z});
            a.push_back({y, x, z});
            a.push_back({y, z, x});
            a.push_back({z, y, x});
            a.push_back({x, z, y});
            a.push_back({z, x, y});
        }
        sort(a.begin(), a.end());
        cout << LIS(a) << endl;
    }
}