#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAXM 300
#define MAXN 300
long long S[MAXM + 1][MAXN + 1];
long long cnt[MAXM + 1][MAXN + 1];
using namespace std;
pair<long long, long long> scs(const string &s1, const string &s2, long long m, long long n)
{
    for (long long i = 0; i <= m; i++)
        for (long long j = 0; j <= n; j++)
            cnt[i][j] = 0;
    for (long long i = 0; i <= m; i++)
    {
        S[i][0] = i;
        cnt[i][0] = 1;
    }
    for (long long i = 0; i <= n; i++)
    {
        S[0][i] = i;
        cnt[0][i] = 1;
    }
    for (long long i = 1; i <= m; i++)
        for (long long j = 1; j <= n; j++)
            if (s1[i - 1] == s2[j - 1])
                S[i][j] = S[i - 1][j - 1] + 1;
            else
                S[i][j] = min(S[i - 1][j], S[i][j - 1]) + 1;
    for (long long i = 1; i <= m; i++)
        for (long long j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                cnt[i][j] = cnt[i - 1][j - 1];
            else
            {
                if (S[i][j] == S[i - 1][j] + 1)
                    cnt[i][j] += cnt[i - 1][j];
                if (S[i][j] == S[i][j - 1] + 1)
                    cnt[i][j] += cnt[i][j - 1];
            }
        }
    return {S[m][n], cnt[m][n]};
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    long long T;
    long long i = 0;
    cin >> T;
    while (T > 0)
    {
        string s1, s2;
        T--;
        cin >> s1 >> s2;
        i++;
        pair<long long, long long> ans = scs(s1, s2, s1.length(), s2.length());
        cout << "Case " << i << ": " << ans.first << " " << ans.second << endl;
    }
}