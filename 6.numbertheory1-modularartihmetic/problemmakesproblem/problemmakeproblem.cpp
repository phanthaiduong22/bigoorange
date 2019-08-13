#include <iostream>
#include <vector>
using namespace std;
long long modularExponentiation(long long a, long long b, long long m)
{
    int res = 1;
    a = a % m;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res * a) % m;
        b = b / 2;
        a = (a * a) % m;
    }
    return res;
}
int modInverser(long long b, long long m)
{
    long long res = modularExponentiation(b, m - 2, m);
    if ((res * b) % m == 1)
        return res;
    return -1;
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    long long j = 0, T;
    long long MAX = 1000000007;
    vector<long long> d(2000005);
    cin >> T;
    long long temp = 1;
    for (long long i = 1; i < 2000005; i++)
    {
        temp = ((temp % MAX) * (i % MAX)) % MAX;
        d[i] = temp;
    }
    while (T > 0)
    {
        long long n, k;
        T--;
        j++;
        cin >> n >> k;
        if (n == 0)
            cout << "Case " << j << ": " << k << endl;
        else
        {
            long long mau = ((d[k - 1] % MAX) * (d[n] % MAX)) % MAX;
            mau = modInverser(mau, MAX);
            long long tu = d[n + k - 1] % MAX;
            long long ans = ((tu % MAX) * (mau % MAX)) % MAX;
            cout << "Case " << j << ": " << ans << endl;
        }
    }
}