#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#define MAX 20 + 5
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[MAX][MAX];
int ans, n;
void trymap(int a[MAX][MAX], int index, int i, int j)
{
    if (index == 8)0
    {
        ans=ans+1;
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        if ((i + dx[k] >= 0) && (i + dx[k] <= n - 1) && (j + dy[k] >= 0) && (j + dy[k] <= n - 1))
            if ((visited[i + dx[k]][j + dy[k]] == false) && (a[i + dx[k]][j + dy[k]] == 1))
            {
                visited[i + .dx[k]][j + dy[k]] = true;
                trymap(a, index+1, i + dx[k], j + dy[k]);
                //index--;
                p.push_back()
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
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                visited[j][j] = false;
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
            {
                if ((visited[j][k] == false) && (a[j][k] == 1))
                {
                    visited[j][k] = true;
                    trymap(a, 1, j, k);
                }
            }
        cout << ans << endl;
    }
}