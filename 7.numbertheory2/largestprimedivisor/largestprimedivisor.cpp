#include <iostream>
#include <vector>

using namespace std;

void phi(long long n)
{
    if(n<0)
        n=-n;
    long long temp = n;
    long long result = n;
    long long ans = 0;
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            result = i;
            ans++;
        }
    }
    if (n > 2)
    {
        result = n;
        ans++;
    }
    if ((result > 2) && (result != temp) && (ans > 1))
        cout << result << endl;
    else
    {
        cout << -1 << endl;
    }
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    long long n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        phi(n);
    }
}