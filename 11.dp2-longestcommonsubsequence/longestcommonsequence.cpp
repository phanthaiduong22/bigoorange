#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define MAXM 6500
#define MAXN 6500
long long L[MAXM + 1][MAXN + 1];

using namespace std;

long long lcs(const string &s1, const string &s2, long long m, long long n)
{
    for (long long i = 0; i <= m; i++)
        for (long long j = 0; j <= n; j++)
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
            {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
    return L[m][n];
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2, s1.length(), s2.length());
}