#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#define MOD 1000000000000000000
using namespace std;

long long ans = 0;
void polyHash(unordered_set<unsigned long long> &d, const string &keys, bool check)
{
    unsigned long long hashValue = 0;
    if (check)
    {
        unsigned long long a = 29;
        for (int i = 0; i < keys.size() - 1; i++)
        {
            hashValue = (keys[i] + a * hashValue);
            d.insert(hashValue);
        }
    }
    else
    {
        unsigned long long a = 1;
        for (int i = keys.size() - 1; i >= 1; i--)
        {
            hashValue = (keys[i] * a + hashValue);
            a = a * 29;
            unordered_set<unsigned long long>::iterator it;
            it = d.find(hashValue);
            if (it != d.end())
            {
                ans++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    long long T;
    long long temp = 0;
    cin >> T;
    while (T > 0)
    {
        temp++;
        string s;
        unordered_set<unsigned long long> d;
        ans = 0;
        T--;
        cin >> s;
        polyHash(d, s, 1);
        polyHash(d, s, 0);
        cout << "Case " << temp << ": " << ans << endl;
    }
}
