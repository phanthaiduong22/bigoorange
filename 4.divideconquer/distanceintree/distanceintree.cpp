#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
vector<int> graph[1000005];
vector<int> visited(500, false);
vector<int> cnt[500]; //chinh sau
int dfs(int s)
{
    int ans = 0;
    cnt[s][0] = 0;
    visited[s] = false;
    if(graph[s].size()==0)  x       
        return 1;
    for (int i = 0; i < graph[s].size(); i++)
    {
        if (visited[graph[s][i]] == false)
        {
            cnt[s][ans]++;
            ans += dfs(graph[s][i]);
        }
    }
    return ans;
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int n, k, x, y;
    cin >> n >> k;
    while (cin >> x >> y)
    {
        graph[x - 1].push_back(y - 1);
        graph[y - 1].push_back(x - 1);
    }
    dfs(0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
            cout << cnt[i][j] << " ";
        cout << endl;
    }
}