#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int T, i = 0;
    cin >> T;
    while (T > 0)
    {
        long long ans = 0;
        string s, s1 = "", s2 = "";
        unordered_map<string, int> d;
        T--;
        i++;
        cin >> s;
        for (int i = 0; i < s.length() - 1; i++)
        {
            s1 += s[i];
            s2 = s[s.length() - i - 1]+s2;
            d.insert({s1,1});
            if (d[s2] > 0)
                ans++;
        }
        cout << "Case " << i << ": " << ans << endl;
    }
}
