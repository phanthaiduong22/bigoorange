#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    string s;
    while (cin >> s)
    {
        vector<long long> d(5015, 0);
        if (s == "0")
            break;
        d[0] = 1;
        d[1] = 1;
        long long temp = (s[0] - '0');
        for (long long i = 2; i <= s.length(); i++)
        {
            if (s[i-1] != '0')
                d[i] += d[i - 1];
            temp = (temp % 10) * 10 + (s[i-1] - '0');
            if (temp >= 10 && temp <= 26)
                d[i] += d[i - 2];
        }
        cout << d[s.length()] << endl;
    }
}