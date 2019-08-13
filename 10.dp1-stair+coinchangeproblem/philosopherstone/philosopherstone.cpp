#include <iostream>
#include <cmath>
#define MAX 105
using namespace std;

int main()
{
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    long long T;
    cin>>T;
    while(T>0)
    {
        long long r,c,maxx,ans=0;
        long long d[MAX][MAX]={0};
        long long a[MAX][MAX];
        T--;
        cin>>r>>c;
        for(long long i=1;i<=r;i++)
            for(long long j=1;j<=c;j++)
                cin>>a[i][j];
        for(long long i=1;i<=c;i++)    
        {
            d[1][i]=a[1][i];
            if(d[1][i]>ans)
                        ans=d[1][i];
        }
        for(long long i=2;i<=r;i++)
            for(long long j=1;j<=c;j++)
                {
                    maxx=max(d[i-1][j-1],max(d[i-1][j],d[i-1][j+1]));
                    d[i][j]=a[i][j]+maxx;
                    if(d[i][j]>ans)
                        ans=d[i][j];
                }
        cout<<ans<<endl;
    }
}