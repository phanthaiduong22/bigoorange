#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> sieveOfEratosthenes(int n)
{
    vector<bool> mark;
    vector<int> primes;
    mark.resize(n + 1, true);
    mark[0] = false;
    mark[1] = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (mark[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
                mark[j] = false;
        }
    }
    for (int i = 1; i <= n; i++)
        if (mark[i] == true)
            primes.push_back(i);
    return primes;
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int n, c;
    vector<int> primes = sieveOfEratosthenes(1000);
    while (cin >> n >> c)
    {
        vector<int>::iterator it;
        it = upper_bound(primes.begin(), primes.end(), n);
        int index = it - 1 - primes.begin();
        cout << n << " " << c << ": ";
        if (index % 2 == 0)
        {
            int a, b;
            if (index / 2 - c + 1 <= 0)
                a = 0;
            else
                a = index / 2 - c + 1;
            if (index / 2 + c - 1 > index)
                b = index;
            else
            {
                b = index / 2 + c - 1;
            }

            for (int i = a; i <= b; i++)
                cout << primes[i] << " ";
        }
        else
        {
            int a, b;
            if (index / 2 - c + 1 <= 0)
                a = 0;
            else
                a = index / 2 - c + 1;
            if (index / 2 + c > index)
                b = index   ;
            else
            {
                b = index / 2 + c;
            }
            for (int i = a; i <= b; i++)
                cout << primes[i] << " ";
        }
        cout << endl;
        cout<<endl;
    }
}