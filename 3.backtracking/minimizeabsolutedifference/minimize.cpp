#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<long long> a;
bool visited[6];
double min_value = 9999999999;
long long id[5];
vector<long long> ans(4, 0);
long long caculate()
{
    double ans = abs((double)a[id[0]] / a[id[1]] - (double)a[id[2]] / a[id[3]]);
    return ans;
}
void backtrack(long long cnt)
{
    if (cnt == 4)
    {
        if (caculate() < min_value)
        {
            min_value = caculate();
            for (long long i = 0; i < 4; i++)
                ans[i] = id[i];
        }
        return;
    }
    for (long long i = 0; i <= 4; i++)
    {
        if (visited[i] == false)
        {
            id[cnt] = i;
            visited[i] = true;
            backtrack(cnt + 1);
            visited[i] = false;
        }
    }
}
int main()
{
    freopen("minimize.inp", "r", stdin);
    freopen("minimize.out", "w", stdout);
    for (long long i = 0; i < 5; i++)
    {
        long long x;
        cin >> x;
        visited[i] = false;
        a.push_back(x);
    }
    long long id[5];
    for(int i=0;i<5;i++)
        backtrack(i);
    for (long long i = 0; i < 4; i++)
        cout << ans[i] << " ";
}