#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <set>
#define MAX 20 + 5
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans, n;
set<long long > s;
void trymap(int a[MAX][MAX], int x, int y, long long mask, int cnt)
{
    if (cnt == 8)
    {
        s.insert(mask);
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        int u = x + dx[k];
        int v = y + dy[k];
        if (a[u][v] == 1 && (((1 << (u * n + v)) & mask) == 0) && u >= 0 && u <= n - 1 && v >= 0 && v <= n - 1)
        {
            mask |= 1 << (u * n + v);
            trymap(a, u, v, mask, cnt + 1);
            mask &= ~(1 << (u * n + v));
        }
    }
}
int main()
{
    freopen("diggeroctaves.inp", "r", stdin);
    freopen("diggeroctaves.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int a[MAX][MAX];
        cin >> n;
        ans = 0;
        char x;
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                cin >> x;
                if (x == 'X')
                    a[j][k] = 1;
                else
                    a[j][k] = 0;
            }
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                trymap(a, j, k, 0, 0);
        ans = s.size();
        s.clear();
        cout << ans << endl;
    }
    return 0;
}