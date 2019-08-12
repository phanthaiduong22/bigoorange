#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define MAXM 150
#define MAXN 150
long long L[MAXM + 1][MAXN + 1];

using namespace std;
string printLCS(const string &s1, const string &s2, long long m, long long n)
{
    string result;
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
    while (cin >> s1 >> s2)
    {
        string result;
        lcs(s1, s2, s1.length(), s2.length());
        result = printLCS(s1, s2, s1.length(), s2.length());
        int i = 0;
        int j = 0, k = 0;
        while (i < s1.length() || j < s2.length())
        {
            if (s1[i] == result[k])
            {
                if (s2[j] == s1[i])
                {
                    cout << s1[i];
                    i++;
                    j++;
                    k++;
                }
                else
                {
                    cout << s2[j];
                    j++;
                }
            }
            else if (s2[j] == result[k])
            {
                if (s1[i] == s2[j])
                {
                    cout << s1[i];
                    i++;
                    j++;
                    k++;
                }
                else
                {
                    cout << s1[i];
                    i++;
                }
            }
            else
            {
                cout << s1[i];
                i++;
            }
        }
        cout << endl;
    }
}