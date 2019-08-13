#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<bool> mark;

int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int a[23]={2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,199,311,337,373,733,919,991};
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        if (n >= 991)
            cout << 0 << endl;
        else
        {
            int ans=0;
            int *it=upper_bound(a,a+22,n);
            int temp=pow(10, trunc(log(n)/log(10)) + 1);
            if(*it<temp)
                ans=*it;
            cout<<ans<<endl;
        }
    }
}
