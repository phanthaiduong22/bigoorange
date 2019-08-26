#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<vector<int>> d;

struct Item
{
    int profit;
    int weight;
};
int knapproblem(vector<Item> &items, int W)
{
    d.assign(items.size() + 1, vector<int>(W + 1, 0));
    for (int i = 1; i < items.size(); i++)
        for (int j = 0; j <= W; j++)
        {
            if (items[i].weight > j)
                d[i][j] = d[i - 1][j];
            else
            {
                int temp = items[i].profit + d[i - 1][j - items[i].weight];
                int temp1 = d[i - 1][j];
                d[i][j] = max(temp, temp1);
            }
        }
    return d[items.size() - 1][W];
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int T;
    cin >> T;
    while (T > 0)
    {
        T--;
        int n, W, x, y, z;
        vector<Item> items;
        items.push_back({0, 0});
        cin >> n >> W;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y >> z;
            items.push_back({x * y, z});
        }
        cout << knapproblem(items, W) << endl;
    }
}