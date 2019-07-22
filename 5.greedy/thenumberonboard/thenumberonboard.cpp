#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    long long k,sum=0;
    string s;
    vector<int>d(11,0);
    cin>>k>>s;
    for(int i=0;i<s.length();i++)
    {
        sum+=s[i]-'0';
        d[s[i]-'0']++;
    }
    int i=-1,ans=0;
    while(sum<k)
    {
        int temp;
        i++;
        //temp1=d[i]*i;
        if(((k-sum)%(9-i))==0)
            temp=(k-sum)/(9-i);
        else
            temp=(k-sum)/(9-i)+1;
        if(temp>d[i])
            temp=d[i];
        sum=sum+temp*(9-i);
        ans+=temp;
    }
    cout<<ans;
}