#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int n,x;
    long long ans=0;
    vector<int>a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++)
        {
            ans+=abs(i+1-a[i]);
        }
    cout<<ans;
}