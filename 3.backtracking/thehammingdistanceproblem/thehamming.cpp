#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool shouldswap(string s, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        if (s[i] == s[end])
            return false;
    }
    return true;
}
void permutations(string s, int l, int r)
{
    if (l >= r)
    {
        cout << s << endl;
        return;
    }
    for (int i = l; i < r; i++)
    {
        bool check = shouldswap(s, l, i);
        if (check == true)
        {
            swap(s[l], s[i]);
            permutations(s, l + 1, r);
            swap(s[l], s[i]);
        }
    }
}
int main()
{
    freopen("thehamming.inp", "r", stdin);
    freopen("thehamming.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        string s = "";
        int n, k;
        cin >> n >> k;
        for (int j = 0; j < n; j++)
        {
            if (j < n - k)
                s += "0";
            else
            {
                s += "1";
            }
        }
        //s = "aabb";
        permutations(s, 0, s.length());
        cout << endl;
    }
}