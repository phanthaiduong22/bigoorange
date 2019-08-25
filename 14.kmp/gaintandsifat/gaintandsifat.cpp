#include <iostream>
#include <string>
#include <vector>

using namespace std;
int ans;
void KMPpreprocess(const string &p, vector<int> &prefix)
{
    int m = p.length();
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
void KMPsearch(const string &t, const string &p, const vector<int> &prefix)
{
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
            {
                j = prefix[j - 1];
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
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int T, casee = 0;
    cin >> T;
    cin.ignore();
    while (T > 0)
    {
        T--;
        casee++;
        cout << "Case " << casee << ": ";
        ans = 0;
        string s, s1, s2 = "", s3 = "";
        getline(cin, s);
        getline(cin, s1);
        for (int i = 0; i < s.length(); i++)
            if (s[i] != ' ')
                s2 += s[i];
        for (int i = 0; i < s1.length(); i++)
            if (s1[i] != ' ')
                s3 += s1[i];
        vector<int> prefix(s3.length());
        KMPpreprocess(s3, prefix);
        KMPsearch(s2, s3, prefix);
        cout << ans << endl;
    }
}