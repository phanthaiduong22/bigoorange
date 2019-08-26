#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
int KMPpreprocess(string &s, vector<int> &prefix)
{
    int index = 0;
    int m = s.length();
    int i = 1;
    int j = 0;
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
        if (prefix[i-1] == 0)
            index = i;
    }
    return index;
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    string s;
    while (cin >> s)
    {
        if (s == "*")
            break;
        vector<int> prefix(s.size());
        int index = KMPpreprocess(s, prefix);
        int n=s.size();
        //cout<<n<<" "<<prefix[n-1]<<endl;
        if((n%(n-prefix[n-1])))
        {
            cout<<1<<endl;
        }
        else
        cout<<n/(n-prefix[n-1])<<endl;
    }
}