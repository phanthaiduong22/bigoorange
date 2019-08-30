#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define MAXM 2005
#define MAXN 2005
long long L[MAXM + 1][MAXN + 1];

using namespace std;
vector<int> printLCS(vector<int> s1, vector<int> s2, int m, int n)
{
    vector<int> result;
    int lengthLCS = L[m][n];
    result.resize(lengthLCS);
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            result[lengthLCS - 1] = s1[i - 1];
            i--;
            j--;
            lengthLCS--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
        {
            j--;
        }
    }
    return result;
}
long long lcs(const vector<int> &s1, const vector<int> &s2, long long m, long long n)
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
    int n, m, k, x;
    cin >> n >> m >> k;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        b.push_back(x);
    }
    int length = lcs(a, b, n, m);
    cout<<min(length+k,n);
}