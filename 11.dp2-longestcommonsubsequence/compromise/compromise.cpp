#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define MAXM 2005
#define MAXN 2005
long long L[MAXM + 1][MAXN + 1];

using namespace std;
void printLCS(vector<string> s1, vector<string> s2, int m, int n)
{
    vector<string> result;
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
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}
long long lcs(vector<string> s1, vector<string> s2, long long m, long long n)
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
    string s;
    vector<string> s1, s2;
    while (1)
    {
        while (cin >> s)
        {
            if (s == "#")
                break;
            else
                s1.push_back(s);
        }
        while (cin >> s)
        {
            if (s == "#")
                break;
            else
                s2.push_back(s);
        }
        lcs(s1, s2, s1.size(), s2.size());
        printLCS(s1, s2, s1.size(), s2.size());
        cout<<endl;
        cin >> s;
        if (s != "#")
        {
            s1.clear();
            s1.push_back(s);
            s2.clear();
        }
        else
            break;
    }
}