#include <iostream>
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
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int T;
    cin >> T;
    while (T > 0)
    {
        T--;
        long long n;
        cin>>n;
        cout<<modularExponentiation(2,n,1000000007)-1<<endl;
    }
}