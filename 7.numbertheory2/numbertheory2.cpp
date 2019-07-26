#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> sieveOfEratosthenes(int n) // sang nguyen to co ban
{
    vector<bool> mark;
    vector<int> primes;
    mark.resize(n + 1, true);
    mark[0] = mark[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (mark[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
                mark[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
        if (mark[i] == true)
            primes.push_back(i);
    return primes;
}
vector<int> segmentedSieve(int left, int right, vector<int> primes)  //sang nguyen to tu left den right voi so lon hon sang nguyen to co ban
{
    if (left == 1)
        left = left + 1;
    vector<bool> mark;
    mark.resize(right - left + 1, true);
    for (int i = 0; i < primes.size() && primes[i] <= sqrt(right); i++)
    {
        int base = (left / primes[i]) * primes[i];
        if (base < left)
            base += primes[i];
        for (int j = base; j <= right; j += primes[i])
        {
            if (j != primes[i])
                mark[j - left] = false;
        }
    }
    vector<int> result;
    for (int i = left; i <= right; i++)
        if (mark[i - left] == true)
            result.push_back(i);
    return result;
}
// cach 1 de tinh phi
int gcd(int a,int b)
{
    int remainder;
    while(b!=0)
    {
        remainder=a%b;
        a=b;
        b=remainder;
    }
    return a;
}
int phi1(int n)
{
    int result =1;
    for(int i=2;i<n;i++)
        if(gcd(i,n)==1)
            result++;
    return result;
}
// cach 2 de tinh phi
long long phi(long long n) //ham phi euler
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
    //dungsangnguyentocoban
    // int n = 25;
    // vector<int> primes = sieveOfEratosthenes(n);
    // for (int i = 0; i < primes.size(); i++)
    //     cout << primes[i] << " ";
    // cout << endl;
    // return 0;

    //sang nguyen to tu left den right voi so lon hon sang nguyen to co ban
    // int left,right;
    // left=12;
    // right=35;
    // vector<int>primes=sieveOfEratosthenes(sqrt(right));
    // vector<int>result=segmentedSieve(left,right,primes);
    // for(int i=0;i<result.size();i++)
    //     cout<<result[i]<<" ";
        
    //ham phi euler cua mot so nguyen duong n la so nguyen duong khong qua n va nguyen to cung nhau voi n;
    //hai so duoc xem la nguyen to cung nhau neu chung co uoc so chung lon nhat la 1


}