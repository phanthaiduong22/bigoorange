#include <iostream>
#include <vector>
using namespace std;
long long r3hash(long long value)
{
    long long sum = 0;
    long long temp = value;
    while (temp > 0)
    {
        sum += temp % 10;
        temp = temp / 10;
    }
    return (value ^ sum);
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    long long n;
    long long collisions = 0, max = 0,max1=-1;
    long long ans = 99999999999;
    vector<long long> d(10000000, 0);
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        long long valuehash;
        valuehash = r3hash(x);
        d[valuehash]++;
        if (d[valuehash] > max)
        {
            max = d[valuehash];
            ans = valuehash;
        }
        else if (d[valuehash] == max)
        {
            if (valuehash < ans)
                ans = valuehash;
        }
        if (d[valuehash] >= 2)
            collisions++;
        if(valuehash>max1)
            max1=valuehash;
    }
    if(max==1)
        ans=max1;
    cout << ans << " " << collisions << endl;
    // cout << (39 ^ 12) << endl;
    // cout << (21 ^ 3) << endl;
    // cout << (18 ^ 9) << endl;
    // cout << (36 ^ 9) << endl;
    // cout << (46 ^ 10) << endl;
    // cout << (34 ^ 7) << endl;
    // cout << (40 ^ 4) << endl;
    // cout << (1 ^ 1) << endl;
    // cout << (31 ^ 4) << endl;
    // cout << (32 ^ 5) << endl;
}