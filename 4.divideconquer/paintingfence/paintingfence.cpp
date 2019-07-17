#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
vector<int>a(5005);
int minoperation(int l,int r,int h)
{
    if(l>=r)
        return 0;
    int min_h=l;
    for(int i=l;i<r;i++)
    {
        if(a[min_h]>a[i])
        {
            min_h=i;
        }
    }
    return min(r-l,a[min_h]-h+minoperation(l,min_h,a[min_h])+minoperation(min_h+1,r,a[min_h]));
}
int main()
{
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<minoperation(0,n,0);
}