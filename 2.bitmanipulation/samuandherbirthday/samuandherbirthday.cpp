#include <iostream>
#include <bitset>
#include <vector>

using namespace std;
int main()
{
    freopen("samuandherbirthday.inp", "r", stdin);
    freopen("samuandherbirthday.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n, k, min = 100;
        vector<string> a;
        cin >> n >> k;
        for (int j = 0; j < n; j++)
        {
            string x;
            cin >> x;
            a.push_back(x);
        }
        for (int e = 0; e < (1 << k); ++e)
        {
            vector<int> b(11, 0);
            int ans = 0, sum = 0, ans1 = 100;
            for (int m = 0; m < k; ++m)
            {
                if (e & (1 << m))
                {
                    ans++;
                    b[m]++;
                }
            }
            for (int p = 0; p < n; p++)
            {
                for (int q = 0; q < k; q++)
                {
                    if (a[p][q] == '1' && b[q] > 0)
                    {
                        sum++;
                        break;
                    }
                }
            }
            if (sum == n)
                ans1 = ans;
            if (ans1 < min)
                min = ans;
        }
        cout << min << endl;
    }
}