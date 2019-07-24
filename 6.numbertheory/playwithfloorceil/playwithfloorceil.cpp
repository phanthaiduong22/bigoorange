#include <iostream>
#include <vector>

using namespace std;
int c;
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
void modInverse(int b, int m)
{
    vector<int> result = extendedEuclid(b, m);
    int gcd = result[0];
    int x = result[1];
    int y = result[2];
    cout << x * c << " " << y * c << endl;
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int T;
    cin >> T;
    while (T > 0)
    {
        int b, m;
        T--;
        cin >> b >> m;
        c = b;
        if (b % m == 0)
        {
            cout << 0 << " " << m << endl;
        }
        else
            modInverse(b / m, b / m + 1);
    }
}