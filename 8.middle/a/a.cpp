#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    long long T;
    cin >> T;
    while (T > 0)
    {
        long long len = 0;
        T--;
        string s, s1 = "", s2 = "";
        cin >> s;
        for (long long i = 0; i < s.length(); i++)
        {
            len += s[i] - '0';
        }
        long long i = 0;
        long long j = len - 1;
        while (i < len)
        {
            s1 = s1 + s[i % s.length()];
            s2 = s[i % s.length()] + s2;
            i++;
            j--;
        }
        if (s1 == s2)
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
    }
}