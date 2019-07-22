#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int x;
        vector<pair<int, int>> a, b;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x < 0)
                a.push_back({-x, i});
            else
                b.push_back({x, i});
        }
        int i = 0, j = 0;
        long long ans = 0;
        while (i < a.size() && j < b.size())
        {
            int add_min = min(a[i].first, b[j].first);
            ans = ans + add_min * abs(a[i].second - b[j].second);
            a[i].first -= add_min;
            b[j].first -= add_min;
            if (a[i].first == 0)
                i++;
            if (b[j].first == 0)
                j++;
        }
        cout << ans << endl;
    }
}