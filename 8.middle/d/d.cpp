#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
long long sumx(vector<long long>a,long long n)
{
    long long ans=0;
    for(long long i=0;i<n;i++)
    {
        ans|=a[i];
    }
    ans=ans*n;
    return ans;
}
int  main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    long long T;
    cin >> T;
    for (long long k = 0; k < T; k++)
    {
        long long n;
        vector<long long> a;
        cin >> n;
        for (long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            a.push_back(x);
        }
        cout<<sumx(a,n)<<endl;
        cout<<(1^2^3);
    }
}
