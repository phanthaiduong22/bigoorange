#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
vector<long long> a;
bool visited[6];
vector<long long> ans(4, 0);
// double caculate(long long id[5])
// {
//     double ans = abs(double((double)a[id[0]] / a[id[1]] - (double)a[id[2]] / a[id[3]]));
//     return ans;
// }
bool compare(long long id[5],vector<long long>ans)
{
    long long p=abs(a[id[0]]*a[id[3]]-a[id[2]]*a[id[1]])*a[ans[1]]*a[ans[3]];
    long long q=abs(a[ans[0]]*a[ans[3]]-a[ans[2]]*a[ans[1]])*a[id[1]]*a[id[3]];
    return p<q;
}
void backtrack(long long id[5], long long cnt)
{
    if (cnt == 4)
    {
        if (compare(id,ans))
        {
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
            backtrack(id, cnt + 1);
            visited[i] = false;
        }
    }
}
int main()
{
    freopen("./minimizeabsolutedifference/minimize.inp", "r", stdin);
    freopen("./minimizeabsolutedifference/minimize.out", "w", stdout);
    for (long long i = 0; i < 5; i++)
    {
        long long x;
        cin >> x;
        visited[i] = false;
        a.push_back(x);
        ans[i]=i;
    }
    long long id[5];
    for (int i = 0; i < 5; i++)
    {
        id[0] = i;
        visited[i] = true;
        backtrack(id, 1);
        visited[i] = false;
    }
    for (long long i = 0; i < 4; i++)
        cout << ans[i] << " ";
}