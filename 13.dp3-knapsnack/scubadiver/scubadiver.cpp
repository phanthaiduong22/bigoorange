#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
struct character
{
    int oxigen;
    int nitrogen;
    int weight;
};
int dp[22][80][1001];
int cal(int t,int a,int i,const vector<character> &v)
{
    if(dp[t][a][i]!=-1)
         return dp[t][a][i];   
    else if(t==0||a==0)
        return 0;
    else
    {
        int tempt=t-v[i].oxigen;
        int tempa=a-v[i].nitrogen;
        int take=v[i].weight+tempt+tempa;
        int notake=
        return min(take,notake);
    }
}
int main()
{
    int T;
    cin>>T;
    while(T>0) 
    {
        int t,a,n,x,y,z;
        vector<character>v;
        T--;
        cin>>t>>a>>n;
        for(int i=0;i<n;i++)
            {
                cin>>x>>y>>z;
                v.push_back({x,y,z});
            }

    }
}