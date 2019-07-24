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
//1
int modInverser(long long b, long long m)//farmat nho ap dung khi m la so nguyen to va b khong chia het cho m O(m)
{
    long long res = modularExponentiation(b, m - 2, m);
    if ((res * b) % m == 1)
        return res;
    return -1;
}
//2
vector<int> extendedEuclid(int b, int m)
{
    vector<int> result;
    int x1 = 0, y1 = 1;
    int x2 = 1, y2 = 0;
    int q, r;
    int x = 1, y = 0;
    while (m != 0)
    {
        q = b / m;
        r = b % m;
        x = x2 - q * x1;
        y = y2 - q * y1;
        x2 = x1, y2 = y1;
        x1 = x, y1 = y;
        b = m, m = r;
    }
    result.push_back(b);
    result.push_back(x2);
    result.push_back(y2);
    return result;
}
void modInverse(int b, int m)//euclid mo rong ap dung khi gcd(b,m)==1. giai phuong trinh bx+my=1 (O(log(m)))
{
    vector<int> result = extendedEuclid(b, m);
    int gcd = result[0];
    int x = result[1];
    int y = result[2];
    cout << x  << " " << y << endl;
}
int main()
{
    //vi du muon tinh (75/5)%11;
    // 9 la nghich dao cua 5 theo modulo 11
    //ans=(75*9)%11;
    modInverser(5,11);//=9
}
// (a+b)%m=((a%m)+(b%m))%m
// (a-b)%m=((a%m)-(b%m))%m
// (a*b)%m=((a%m)*(b%m))%m
// (a/b)%m=(a*c)%m voi c la nghich dao cua b theo m ap dung fermat nho hoac euclid mo rong