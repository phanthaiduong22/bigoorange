#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <set>
#include <bitset>
#define MAX 20 + 5
using namespace std;
long long dx[4] = {-1, 0, 1, 0};
long long dy[4] = {0, 1, 0, -1};
long long ans, n;
long long a[MAX][MAX];
//bool visited[MAX][MAX];
set<long long> s;
void trymap(long long x, long long y, long long mask, long long cnt)
{
    if (cnt == 8)
    {
        //cout << bitset<64>(mask) << endl;
        s.insert(mask);
        return;
    }
    for (long long k = 0; k < 4; k++)
    {

        long long u = x + dx[k];
        long long v = y + dy[k];
        if (a[u][v] == 1 && u >= 0 && u <= n - 1 && v >= 0 && v <= n - 1 && (((1LL << (u * n + v)) & mask) == 0))
        {
            //cout << u << " " << v << " " << mask << " " << bitset<64>(mask) << " " << cnt << endl;
            mask |= 1LL << (u * n + v);
            //visited[u][v] = true;
            trymap(u, v, mask, cnt + 1);
            mask &= ~(1LL << (u * n + v));
            //visited[u][v] = false;
        }
    }
}
int main()
{
    freopen("diggeroctaves.inp", "r", stdin);
    freopen("diggeroctaves.out", "w", stdout);
    long long T;
    cin >> T;
    for (long long i = 0; i < T; i++)
    {
        cin >> n;
        ans = 0;
        char x;
        for (long long j = 0; j < n; j++)
            for (long long k = 0; k < n; k++)
            {
                cin >> x;
                if (x == 'X')
                    a[j][k] = 1;
                else
                    a[j][k] = 0;
                //visited[j][k] = false;
            }
        for (long long j = 0; j < n; j++)
            for (long long k = 0; k < n; k++)
            {
                if (a[j][k] == 1)
                {
                    long long mask = 0;
                    //visited[j][k] = true;
                    mask |= 1LL << (j * n + k);
                    trymap(j, k, mask, 1);
                }
            }
        ans = s.size();
        // set<long long>::iterator it;
        // for (it = s.begin(); it != s.end(); it++)
        //     cout << bitset<64>(*it) << endl;
        cout << ans << endl;
        s.clear();
    }
    return 0;
}