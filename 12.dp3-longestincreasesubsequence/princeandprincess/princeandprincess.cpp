#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> result;
vector<int> path;
#define MAXM 150
#define MAXN 150
long long L[MAXM + 1][MAXN + 1];

using namespace std;
vector<int> printLCS(vector<int> s1, vector<int> s2, long long m, long long n)
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
long long lcs(vector<int> s1, vector<int> s2, long long m, long long n)
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
void printLIS(vector<int> &a, int length)
{
    vector<int> b;
    int i = result[length - 1];
    while (i >= 0)
    {
        b.push_back(a[i]);
        i = path[i];
    }
    for (int i = b.size() - 1; i >= 0; i--)
        cout << b[i] << " ";
}
int lowerBound(vector<int> &a, vector<int> &sub, int n, int x)
{
    int left = 0;
    int right = n;
    int pos = right;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        int index = sub[mid];
        if (a[index] >= x)
        {
            pos = mid;
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return pos;
}
int LIS(vector<int> &a)
{
    int length = 1;
    path.assign(a.size(), -1);
    result.push_back(0);
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] < a[result[0]])
        {
            result[0] = i;
        }
        else if (a[i] >= a[result[length - 1]])
        {
            path[i] = result[length - 1];
            result.push_back(i);
            length++;
        }
        else
        {
            int pos = lowerBound(a, result, length, a[i]);
            path[i] = result[pos - 1];
            result[pos] = i;
        }
    }
    return length;
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int T;
    cin >> T;
    for (int k = 0; k < T; k++)
    {
        int x, n, p, q;
        vector<int> a, b, result;
        cin >> n >> p >> q;
        for (int i = 0; i < p + 1; i++)
        {
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < q + 1; i++)
        {
            cin >> x;
            b.push_back(x);
        }
        lcs(a, b, a.size(), b.size());
        result = printLCS(a, b, a.size(), b.size());
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
    }
}