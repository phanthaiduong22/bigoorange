#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#define MOD 1000000000000000007
using namespace std;
unordered_set<unsigned long long> d;
string s;
long long ans = 0;
void polyHash1()
{
    unsigned long long hashValue = 0;
    unsigned long long a = 29;
    for (int i = 0; i < s.size() - 1; i++)
    {
        hashValue = (s[i] + a * hashValue);
        d.insert(hashValue);
    }
}
long long polyHash2()
{
    unsigned long long a = 1;
    unsigned long long hashValue = 0;
    for (int i = s.size() - 1; i >= 1; i--)
    {
        hashValue = (s[i] * a + hashValue);
        a = a * 29;
        unordered_set<unsigned long long>::iterator it;
        it = d.find(hashValue);
        if (it != d.end())
        {
            ans++;
        }
    }
    return ans;
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
        ans = 0;
        T--;
        cin >> s;
        polyHash1();
        polyHash2();
        cout << "Case " << temp << ": " << ans << endl;
        d.clear();
    }
}
