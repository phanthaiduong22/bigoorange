#include <iostream>
#include <string>
#include <vector>

using namespace std;
int ans;
void kmppreprocess(const vector<int> &p, vector<int> &prefix)
{
    prefix[0] = 0;
    int m = p.size();
    int i = 1;
    int j = 0;
    while (i < m)
    {
        if (p[i] == p[j])
        {
            j++;
            prefix[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
                j = prefix[j - 1];
            else
            {
                prefix[i] = 0;
                i++;
            }
        }
    }
}
void KMPsearch(const vector<int> &t, const vector<int> &p, const vector<int> &prefix)
{
    int n = t.size();
    int m = p.size();
    int i = 0, j = 0;
    while (i < n)
    {
        if (p[j] == t[i])
        {
            j++;
            i++;
        }
        if (j == m)
        {
            ans++;
            j = prefix[j - 1];
        }
        else if (i < n && p[j] != t[i])
        {
            if (j != 0)
            {
                j = prefix[j-1];
            }
            else
            {
                i++;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int n, m, x;
    ans = 0;
    cin >> n >> m;
    vector<int> a, b, a1, b1;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
        if (i >= 1)
            a1.push_back(a[i] - a[i - 1]);
    }
    if (m == 1)
    {
        cout << n;
        return 0;
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            b.push_back(x);
            if (i >= 1)
                b1.push_back(b[i] - b[i - 1]);
        }
        vector<int> prefix(b1.size());
        kmppreprocess(b1, prefix);
        KMPsearch(a1, b1, prefix);
        cout << ans;
        return 0;
    }
}