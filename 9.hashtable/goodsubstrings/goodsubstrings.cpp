#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    string s, alphabet;
    int k;
    unordered_set<uint64_t> myset;
    unordered_set<uint64_t>::iterator it;
    while (cin >> s >> alphabet >> k)
    {
        int bad = 0, ans = 0;
        myset.clear();
        for (int i = 0; i < s.length(); i++)
        {
            bad = 0;
            uint64_t hashValue = 0;
            unsigned long long a = 29;
            for (int j = i; j < s.length(); j++)
            {
                hashValue = (s[j] + a * hashValue);
                if (alphabet[s[j] - 97] == '0')
                    bad++;
                if(bad<=k)
                {
                    myset.insert(hashValue);
                }
            }
        }
        cout << myset.size() << endl;
    }
}