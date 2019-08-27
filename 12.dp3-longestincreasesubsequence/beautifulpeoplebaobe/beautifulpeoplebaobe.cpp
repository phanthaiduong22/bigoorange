#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
const int INT_MAX = (1 << 31);
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;
typedef long long ll;
struct person
{
    int s;
    int b;
    person() {}
    person(int strength, int beauty) : s(strength), b(beauty) {}
    bool operator<(const person &another)
    {
        return  ((s <= another.s && b >= another.b) || (s >= another.s && b <= another.b));
    }
};
vector<person> a;
int dp[100005], T[100005];
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    FASTIO;
    int maxlen = 0, pos;
    int n, s, b;
    cin >> n;
    a.push_back(person(0, 0));
    for (int i = 1; i <= n; i++)
        dp[i] = 1;
    for (int i = 1; i <= n; i++)     
    {
        cin >> s >> b;
        a.push_back(person(s, b));
    }
    a.push_back(person(INT_MAX, INT_MAX));
    for (int i = n; i >= 1; i--)
    {
        int jmin = n + 1;
        for (int j = n; j > i; j--)
        {
            if (!(a[i] < a[j]) && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                jmin = j;
            }
        }
        T[i] = jmin;
        if (dp[i] > maxlen)
        {
            maxlen = dp[i];
            pos = i;
        }
    }
    cout << maxlen << endl;
    maxlen--;
    cout << pos << " ";
    while (maxlen--)
    {
        if (T[pos] != n + 1)
            cout << T[pos] << " ";
        pos = T[pos];
    }
    system("pause");
    return 0;
}
