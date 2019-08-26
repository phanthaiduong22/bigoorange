#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void KMPprefix(string s, vector<int> &prefix)
{
    prefix[0] = 0;
    int m = s.length();
    int j = 0;
    int i = 1;
    while (i < m)
    {
        if (s[i] == s[j])
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
int checksubstring(const string &s, vector<int> prefix)
{
    for (int i = 1; i < s.length() - 1; i++)
    {
        if (prefix[i] == prefix[s.length() - 1])
        {
            return i;
        }
    }
    return 0;
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    string s;
    cin >> s;
    vector<int> prefix(s.size());
    KMPprefix(s, prefix);
    int n = s.length();
    if (prefix[n-1] == 0)
    {
        cout << "Just a legend" << endl;
    }
    else if (checksubstring(s, prefix))
    {
        for (int i = 0; i < prefix[n-1]; i++)
        {
            cout << s[i];
        }
    }
    else if (prefix[prefix[n - 1] - 1] == 0)
        cout << "Just a legend" << endl;
    else
    {
        for (int i = 0; i < prefix[prefix[n - 1] - 1]; i++)
            cout << s[i];
    }
}