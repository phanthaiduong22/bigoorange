#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long phi(long long n) 
{
    long long result = n;
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            result = result/i*(i-1);
        }
    }
    if (n > 1)
        result=result/n*(n-1);
    return result;
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int n;
    vector<int>ans(50006,0);
    ans[1]=1;
    ans[2]=3;
    for(int i=3;i<=50005;i++)
    {
        ans[i]=ans[i-1]+phi(i)*2;
    }
    while (cin >> n)
    {
        if (n == 0)
            break;
        cout<<ans[n]<<endl;
    }
}