#include <iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int a = 0, b = 1, ans = 1;
        while (((a % n) + (b % n)) % n != 0)
        {
            a = ((a % n) + (b % n)) % n;
            b = ((b % n) * (10 % n)) % n;
            ans++;
        }
        cout << ans << endl;
    }
}