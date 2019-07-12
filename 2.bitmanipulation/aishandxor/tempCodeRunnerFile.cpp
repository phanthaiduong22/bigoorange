#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main()
{
    freopen("aishandxor.inp", "r", stdin);
    freopen("aishandxor.out", "w", stdout);
    int n, q, l, r, x, number = 0;
    vector<int> n0(100000, 0);
    vector<int> n1(100000, 0);
    cin >> n;
    cin >> x;
    if (x == 0)
        n0[0]++;
    else
        n1[0]++;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        if (x == 0)
        {
            n0[i] = n0[i - 1] + 1;
            n1[i] = n1[i - 1];
        }
        else
        {
            n1[i] = n1[i - 1] + 1;
            n0[i] = n0[i - 1];
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        int number_zero = 0, number_one = 0;
        number_zero = n0[r - 1] - n0[l - 2];
        number_one = n1[r - 1] - n1[l - 2];
        cout << (number_one & 1) << " " << number_zero << endl;
    }
}