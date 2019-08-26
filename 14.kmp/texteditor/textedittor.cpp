#include <iostream>
#include <vector>
#include <string>

using namespace std;
void KMPpreprocess(const string &p, vector<int> &prefix)
{
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
int KMPsearch(const string &t, const string &p, vector<int> &prefix, int lowerbound)
{
    int ans = 0;
    int n = t.length();
    int m = p.length();
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
                j = prefix[j - 1];
            else
                i++;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    string text, pattern;
    int n;
    getline(cin, text);
    getline(cin, pattern);
    cin >> n;
    string ans = "IMPOSSIBLE";
    int l = 0;
    int r = pattern.size();
    int mid;
    int size = pattern.size();
    vector<int> prefix(size);
    KMPpreprocess(pattern, prefix);
    while (l <= r)
    {
        mid = (l + r) / 2;
        string temp = "";
        for (int i = 0; i < mid; i++)
        {
            temp += pattern[i];
        }
        if (temp == "")
            break;
        int cnt = KMPsearch(text, temp, prefix, n);
        if (cnt >= n)
        {
            ans = temp;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans;
}