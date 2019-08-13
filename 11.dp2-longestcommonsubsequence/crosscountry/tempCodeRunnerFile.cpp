#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define MAXM 2005
#define MAXN 2005
long long L[MAXM + 1][MAXN + 1];

using namespace std;

long long lcs(vector<long long> s1, vector<long long> s2, long long m, long long n)
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
    long long T;
    cin >> T;
    while (T > 0)
    {
        vector<long long> s1, s2;
        long long m = 0, n = 0, max = 0, x;
        while (cin >> x)
        {
            if (x == 0)
                break;
            m++;
            s1.push_back(x);
        }
        T--;
        while (1)
        {
            while (cin >> x)
            {
                if (x == 0)
                {
                    long long temp = lcs(s1, s2, m, n);
                    if (temp > max)
                        max = temp;
                    break;
                }
                n++;
                s2.push_back(x);
            }
            cin>>x;
            if(x==0)
                break;
            else
            {
                s2.clear();
                s2.push_back(x);
                n=1;
            }
        }
        cout << max<<endl;
    }
}