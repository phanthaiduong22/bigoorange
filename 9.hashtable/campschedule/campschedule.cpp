#include <iostream>
#include <string>
#include <vector>
using namespace std;
void KMPpreprocess(const string &p, vector<int> &prefix)
{
    prefix[0] = 0;
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
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    string s, t;
    int ones = 0, zeros = 0, ones1 = 0, zeros1 = 0;
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            ones++;
        else
        {
            zeros++;
        }
    }
    if (s.size() < t.size())
        cout << s;
    else
    {
        string ans = "", temp = "";
        vector<int> prefix(t.size());
        KMPpreprocess(t, prefix);
        int maxPrefixSuffix = prefix[t.size() - 1];
        for (int i = 0; i < t.size() - maxPrefixSuffix; i++)
        {
            temp += t[i];

            if (t[i] == '1')
                ones1++;
            else
                zeros1++;
        }
        while (ones1 <= ones && zeros1 <= zeros)
        {
            ans += temp;
            ones -= ones1;
            zeros -= zeros1;
        }
        int j = 0;
        while (ones > 0 || zeros > 0)
        {
            if (temp[j] == '1' && ones > 0)
            {
                ans += '1';
                ones--;
                j++;
            }
            if (temp[j] == '0' && zeros > 0)
            {
                ans += '0';
                zeros--;
                j++;
            }
            if ((temp[j] == '1' && ones == 0) || (temp[j] == '0' && zeros == 0))
                break;
        }
        for (int i = 0; i < ones; i++)
            ans += '1';
        for (int i = 0; i < zeros; i++)
            ans += '0';
        cout << ans;
    }
}