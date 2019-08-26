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
void printItems(vector<Item> &items, int W)
{
    cout << "List Items: " << endl;
    for (int i = items.size() - 1; i > 0; i--)
    {
        if (d[i][W] != d[i - 1][W])
        {
            cout << items[i].profit << " " << items[i].weight << endl;
            W-=items[i].weight;
        }
    }
}
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
    int n, W, x, y;
    vector<Item> items;
    items.push_back({0, 0});
    cin >> n >> W;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        items.push_back({x, y});
    }
    cout << knapproblem(items, W) << endl;
    printItems(items,W);
}