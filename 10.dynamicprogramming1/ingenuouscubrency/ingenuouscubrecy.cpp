#include <iostream>
#include <vector>

using namespace std;
long long coinchangeproblem(vector<long long> coins, long long n, long long m)
{
    vector<long long> result(n + 1);
    result[0] = 1;
    for (long long i = 0; i < m; i++)
    {
        for (long long j = coins[i]; j <= n; j++)
        {
            result[j] += result[j - coins[i]];
        }
    }
    return result[n];
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    long long n;
    vector<long long> coins;
    for (long long i = 1; i <=21; i++)
    {
        coins.push_back(i*i*i);
    }
    while(cin>>n)
    {
        cout<<coinchangeproblem(coins,n,21)<<endl;
    }
}