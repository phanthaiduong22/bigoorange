#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int T;
    cin >> T;
    while (T > 0)
    {
        T--;
        int n, b, k, x, ans = 0;
        cin >> n >> b;
        for (int i = 0; i < b; i++)
        {
            cin >> k;
            int ans1 = 1;
            for (int j = 0; j < k; j++)
            {
                cin >> x;
                ans1 = ((ans1 % n) * (x % n)) % n;
            }
            ans = ((ans % n) + (ans1 % n)) % n;
        }
        cout << ans % n << endl;
    }
}