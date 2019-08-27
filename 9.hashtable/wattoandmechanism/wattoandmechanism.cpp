#include <iostream>
#include <unordered_set>
using namespace std;
unordered_set<unsigned long long> d;

unsigned long long polyHash(string keys)
{
    unsigned long long hashValue = 0;
    unsigned long long a = 33;
    for (int i = 0; i < keys.size(); i++)
        hashValue = (keys[i] + a * hashValue);
    return hashValue;
}
bool polyHashm(string keys)
{
    unsigned long long hashValue = 0;
    unsigned long long a = 33;
    for (int i = 0; i < keys.size(); i++)
        hashValue = (keys[i] + a * hashValue);
    unordered_set<unsigned long long>::iterator it;

    //return hashValue & 0x7FFFFFFF;
    unsigned long long b = 1;
    for (int i = keys.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            unsigned long long temp = hashValue;
            if ((int)keys[i] != j + 97)
            {
                temp = (temp - keys[i] * b + (j + 97) * b);
                it = d.find(temp);
                if (it != d.end())
                {
                    return true;
                }
            }
        }
        b = b * 33;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int n, m;
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        d.insert(polyHash(s));
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (polyHashm(s))
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
    }
}