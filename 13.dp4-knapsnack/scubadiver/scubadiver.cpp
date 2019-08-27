#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXoxi 22
#define MAXnitro 80
#define MAXweight 801
#define INF 1e9
using namespace std;
vector<vector<vector<int>>> dp;
struct member
{
    int oxy;
    int nitro;
    int weight;
};
vector<member> b;
int solve(int i, int co, int cn)
{
    if (dp[i][co][cn] != -1)
        return dp[i][co][cn];
    if (co == 0 && cn == 0)
        dp[i][co][cn]=0;
    else if(i==0)
        dp[i][co][cn]=INF;
    else
        dp[i][co][cn]=min(solve(i-1,co,cn),solve(i-1,max(co-b[i-1].oxy,0),max(cn-b[i-1].nitro,0))+b[i-1].weight);
    return dp[i][co][cn];
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int c;
    cin >> c;
    while (c > 0)
    {
        int t, a, n, x, y, z;
        c--;
        cin >> t >> a;
        cin >> n;
        dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(MAXoxi, vector<int>(MAXnitro, -1)));
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y >> z;
            b.push_back({x, y, z});
        }
        cout<<solve(n, t, a)<<endl;
        b.clear();
        dp.clear();
    }
}