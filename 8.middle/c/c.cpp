#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int main()
{
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int T;
    cin>>T;
    for (int j = 0; j < T; j++)
    {
        int n;
        cin>>n;
        vector<int>a;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            a.push_back(x);
        }
        if(n&1)
        {
            int i=0;
            int ans=0;
            while(i<n)
            {
                ans^=a[i];
                i+=2;
            }
            cout<<ans<<endl;
        }
        else
            cout<<0<<endl;
    }
}   