#include <iostream>
#include <bitset>
#include <vector>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
using namespace std;

int main()
{
    freopen("mattey.inp", "r", stdin);
    freopen("mattey.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long x, y, mu = -1;
        vector<int> a;
        cin >> x >> y;
        while (y > 0)
        {
            mu++;
            if (y & 1)
                a.push_back(mu);
            y >>= 1;
        }
        for(int j=a.size()-1;j>=0;j--)
        {
            cout<<"("<<x<<"<<"<<a[j]<<")";
            if(j!=0)
                cout<<" + ";
        }
        cout<<endl;
    }
}