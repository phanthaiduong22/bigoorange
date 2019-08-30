#include <iostream>
#include <string>
#include <vector>
#define INF 1e9
using namespace std;
void kmppreprocess(const string &p, vector<int> &prefix)
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
    int n;
    string s;
    while (cin >> n >> s)
    {
        if (n == -1 && s == "*")
            break;
        vector<int> prefix(s.length());
        kmppreprocess(s, prefix);
        if (1 + ((n - s.length()) / (s.length() - prefix[s.length() - 1])) > INF)
            cout << 0 << endl;
        else
            cout << 1 + ((n - s.length()) / (s.length() - prefix[s.length() - 1])) << endl;
    }
}