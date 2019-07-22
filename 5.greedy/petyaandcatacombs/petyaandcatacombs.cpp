#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int ans=1;
    int n;
    vector<int>t(200005,0);
    t[0]=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(t[x]>0)
        {
            t[i]=ans;
            t[x]=0;
        }
        else
        {
            ans++;
            t[i]=ans;
        }
    }
    cout<<ans;
}